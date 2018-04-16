/*
 @Date    : 2018-04-14 16:18:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3236136.html
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

void f1(int n)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "f1 is running and n = " << n << "\n";
        std::cout << "Thread " << n << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return;
}

void f2(int &n)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return;
}

int main()
{
    int n = 0;
    std::thread t1; // t1 is not a thread
    std::thread t2(f1, n + 1); // pass by value
    std::thread t3(f2, std::ref(n)); // pass by reference
    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << '\n';
    return 0;
}
