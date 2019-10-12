/*
 @Date    : 2018-04-16 12:45:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3301408.html
 */

#include <iostream>             // std::cout
#include <atomic>               // std::atomic
#include <thread>               // std::thread, std::this_thread::yield

std::atomic<int> foo(0);

void set_foo(int x)
{
    foo = x; // 调用 std::atomic::operator=().
    return;
}

void print_foo()
{
    while (foo == 0)
    { // wait while foo == 0
        std::this_thread::yield();
    }
    std::cout << "foo: " << foo << '\n';
    return;
}

int main()
{
    std::thread first(print_foo);
    std::thread second(set_foo, 10);
    first.join();
    second.join();
    return 0;
}
