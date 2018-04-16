/*
 @Date    : 2018-04-14 17:37:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3237213.html
 */

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

volatile int counter(0); // non-atomic counter
std::mutex mtx;           // locks access to counter

void attempt_10k_increases()
{
    for (int i = 0; i < 10000; ++i)
    {
        if (mtx.try_lock())
        {   // only increase if currently not locked:
            ++counter;
            mtx.unlock();
        }
        // ++counter;
    }
}

int main (int argc, const char* argv[])
{
    std::thread threads[10];
    for (int i = 0; i < 10; ++i)
        threads[i] = std::move(std::thread(attempt_10k_increases));

    for (auto& th : threads) th.join();
    std::cout << counter << " successful increases of the counter.\n";

    return 0;
}

