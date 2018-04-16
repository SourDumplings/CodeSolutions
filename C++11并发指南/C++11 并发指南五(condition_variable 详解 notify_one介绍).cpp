/*
 @Date    : 2018-04-16 09:57:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3252041.html
 */

#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable

std::mutex mtx;
std::condition_variable cv;

int cargo = 0; // shared value by producers and consumers

void consumer()
{
    std::unique_lock<std::mutex> lck(mtx);
    while (cargo == 0)
        cv.wait(lck);
    std::cout << cargo << " has been consumed"<< '\n';
    cargo = 0;
    return;
}

void producer(int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    cargo = id;
    std::cout << cargo << " has been produced\n";
    cv.notify_one();
    return;
}

int main()
{
    std::thread consumers[10], producers[10];

    // spawn 10 consumers and 10 producers:
    for (int i = 0; i < 10; ++i)
    {
        consumers[i] = std::thread(consumer);
        producers[i] = std::thread(producer, i + 1);
    }

    // join them back:
    for (int i = 0; i < 10; ++i)
    {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}
