/*
 @Date    : 2018-04-16 18:24:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3252092.html
 */

#include <unistd.h>

#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int kItemRepositorySize  = 4; // Item buffer size.
static const int kItemsToProduce  = 10;   // How many items we plan to produce.

struct ItemRepository
{
    int item_buffer[kItemRepositorySize];
    size_t read_position;
    size_t write_position;
    size_t item_counter;
    std::mutex mtx;
    std::mutex item_counter_mtx;
    std::condition_variable repo_not_full;
    std::condition_variable repo_not_empty;
} gItemRepository;

typedef struct ItemRepository ItemRepository;

static std::mutex omtx;


void ProduceItem(ItemRepository *ir, int item)
{
    std::unique_lock<std::mutex> lock(ir->mtx);
    while (((ir->write_position + 1) % kItemRepositorySize)
            == ir->read_position)
    {   // item buffer is full, just wait here.
        omtx.lock();
        std::cout << "Producer is waiting for an empty slot...\n";
        omtx.unlock();

        (ir->repo_not_full).wait(lock);
    }

    (ir->item_buffer)[ir->write_position] = item;
    ir->write_position = (ir->write_position + 1) % kItemRepositorySize;

    (ir->repo_not_empty).notify_all();
    lock.unlock();
    return;
}

int ConsumeItem(ItemRepository *ir)
{
    int data;
    std::unique_lock<std::mutex> lock(ir->mtx);
    // item buffer is empty, just wait here.
    while (ir->write_position == ir->read_position)
    {
        omtx.lock();
        std::cout << "Consumer is waiting for items...\n";
        omtx.unlock();

        (ir->repo_not_empty).wait(lock);
    }

    data = (ir->item_buffer)[ir->read_position];
    ir->read_position = (ir->read_position + 1) % kItemRepositorySize;

    (ir->repo_not_full).notify_all();
    lock.unlock();

    return data;
}

void ProducerTask()
{
    bool ready_to_exit = false;
    while (1)
    {
        sleep(1);
        std::unique_lock<std::mutex> lock(gItemRepository.item_counter_mtx);
        if (gItemRepository.item_counter < kItemsToProduce)
        {
            // 生产者也要计数
            ++(gItemRepository.item_counter);
            ProduceItem(&gItemRepository, gItemRepository.item_counter);
            omtx.lock();
            std::cout << "Producer thread " << std::this_thread::get_id()
                      << " is producing the " << gItemRepository.item_counter
                      << "^th item" << std::endl;
            omtx.unlock();
        }
        else ready_to_exit = true;
        lock.unlock();
        if (ready_to_exit == true) break;
    }
    omtx.lock();
    std::cout << "Producer thread " << std::this_thread::get_id()
              << " is exiting..." << std::endl;
    omtx.unlock();

    return;
}

void ConsumerTask()
{
    static int item_consumed = 0;
    while (1)
    {
        sleep(1);
        ++item_consumed;
        if (item_consumed <= kItemsToProduce)
        {
            int item = ConsumeItem(&gItemRepository);
            omtx.lock();
            std::cout << "Consumer thread " << std::this_thread::get_id()
                      << " is consuming the " << item << "^th item" << std::endl;
            omtx.unlock();

        }
        else break;
    }
    omtx.lock();
    std::cout << "Consumer thread " << std::this_thread::get_id()
              << " is exiting..." << std::endl;
    omtx.unlock();

    return;
}

void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0;
    ir->read_position = 0;
    ir->item_counter = 0;
    return;
}

int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer1(ProducerTask);
    std::thread producer2(ProducerTask);
    std::thread producer3(ProducerTask);
    std::thread producer4(ProducerTask);
    std::thread consumer(ConsumerTask);

    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();
    consumer.join();
    return 0;
}
