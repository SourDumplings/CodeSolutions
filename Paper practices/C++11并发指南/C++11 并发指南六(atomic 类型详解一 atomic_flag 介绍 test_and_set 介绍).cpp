/*
 @Date    : 2018-04-16 12:02:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3252056.html
 */

#include <iostream>                // std::cout
#include <atomic>                // std::atomic_flag
#include <thread>                // std::thread
#include <vector>                // std::vector
#include <sstream>                // std::stringstream

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_number(int x)
{
    while (lock_stream.test_and_set());
    stream << "thread #" << x << '\n';
    lock_stream.clear();
    return;
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(append_number, i));
    for (auto & th : threads)
        th.join();

    std::cout << stream.str() << std::endl;;
    return 0;
}
