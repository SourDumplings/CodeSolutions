/*
 @Date    : 2018-04-16 16:37:24
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

#include <ctime>
#include <random>

static const int kItemRepositorySize  = 10; // Item buffer size.
static const int kItemsToProduce  = 1000;   // How many items we plan to produce.

struct ItemRepository
{
    int item_buffer[kItemRepositorySize]; // 产品缓冲区, 配合 read_position 和 write_position 模型环形队列.
    size_t read_position; // 消费者读取产品位置.
    size_t write_position; // 生产者写入产品位置.
    std::mutex mtx; // 互斥量, 保护产品缓冲区
    std::condition_variable repo_not_full; // 条件变量, 指示产品缓冲区不为满.
    std::condition_variable repo_not_empty; // 条件变量, 指示产品缓冲区不为空.
} gItemRepository; // 产品库全局变量, 生产者和消费者操作该变量.

typedef struct ItemRepository ItemRepository;

static std::mutex omtx;
static std::default_random_engine e(time(nullptr));
static std::uniform_int_distribution<unsigned> u(0, 10);


void ProduceItem(ItemRepository *ir, int item)
{
    std::unique_lock<std::mutex> lock(ir->mtx);
    while (((ir->write_position + 1) % kItemRepositorySize)
            == ir->read_position)
    { // item buffer is full, just wait here.
        omtx.lock();
        std::cout << "Producer is waiting for an empty slot...\n";
        omtx.unlock();
        (ir->repo_not_full).wait(lock); // 生产者等待"产品库缓冲区不为满"这一条件发生.
    }

    (ir->item_buffer)[ir->write_position] = item; // 写入产品.
    ir->write_position = (ir->write_position + 1) % kItemRepositorySize;

    (ir->repo_not_empty).notify_all(); // 通知消费者产品库不为空.
    lock.unlock(); // 解锁.

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

        (ir->repo_not_empty).wait(lock); // 消费者等待"产品库缓冲区不为空"这一条件发生.
    }

    data = (ir->item_buffer)[ir->read_position]; // 读取某一产品
    ir->read_position = (ir->read_position + 1) % kItemRepositorySize;

    (ir->repo_not_full).notify_all(); // 通知消费者产品库不为满.
    lock.unlock(); // 解锁.

    return data; // 返回产品.
}


void ProducerTask() // 生产者任务
{
    for (int i = 1; i <= kItemsToProduce; ++i)
    {
        sleep(u(e)/5);

        omtx.lock();
        std::cout << "Produce the " << i << "^th item..." << std::endl;
        omtx.unlock();

        ProduceItem(&gItemRepository, i); // 循环生产 kItemsToProduce 个产品.
    }
    return;
}

void ConsumerTask() // 消费者任务
{
    static int cnt = 0;
    while (1)
    {
        // sleep(1);

        sleep(u(e)/10);

        int item = ConsumeItem(&gItemRepository); // 消费一个产品.

        omtx.lock();
        std::cout << "Consume the " << item << "^th item" << std::endl;
        omtx.unlock();

        if (++cnt == kItemsToProduce) break; // 如果产品消费个数为 kItemsToProduce, 则退出.
    }
    return;
}

void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0; // 初始化产品写入位置.
    ir->read_position = 0; // 初始化产品读取位置.

    return;
}

int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer(ProducerTask); // 创建生产者线程.
    std::thread consumer(ConsumerTask); // 创建消费之线程.
    producer.join();
    consumer.join();
    return 0;
}
