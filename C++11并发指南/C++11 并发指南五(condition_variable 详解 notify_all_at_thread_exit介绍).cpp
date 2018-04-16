/*
 @Date    : 2018-04-16 10:25:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3252041.html
 */

#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id (int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) cv.wait(lck);
    // ...
    std::cout << "thread " << id << '\n';
    return;
}

void go()
{
    std::unique_lock<std::mutex> lck(mtx);
    std::notify_all_at_thread_exit(cv, std::move(lck));
    ready = true;
    return;
}

int main ()
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_id, i);
    std::cout << "10 threads ready to race...\n";

    std::thread(go).detach();   // go!

    for (auto &th : threads) th.join();

    return 0;
}
