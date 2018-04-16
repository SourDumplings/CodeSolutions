/*
 @Date    : 2018-04-14 18:36:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3237213.html
 */

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c)
{
    // critical section (exclusive access to std::cout signaled by lifetime of lck):
    // std::lock_guard<std::mutex> lck(mtx);
    std::unique_lock<std::mutex> lck(mtx);
    for (int i = 0; i < n; ++i)
    {
        std::cout << c;
    }
    std::cout << '\n';
    return;
}

int main ()
{
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');

    th1.join();
    th2.join();

    return 0;
}
