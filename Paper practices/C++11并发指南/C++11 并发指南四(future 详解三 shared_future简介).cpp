/*
 @Date    : 2018-04-15 14:20:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3280643.html
 */

#include <iostream>       // std::cout
#include <future>         // std::async, std::future, std::shared_future

int do_get_value() { return 10; }

int main ()
{
    std::future<int> fut = std::async(do_get_value);
    std::shared_future<int> shared_fut = fut.share();

    // 共享的 future 对象可以被多次访问.
    std::cout << "value: " << shared_fut.get() << '\n';
    std::cout << "its double: " << shared_fut.get() * 2 << '\n';
    //
    // 普通的future对象不能访问两次
    // std::cout << "value: " << fut.get() << '\n';
    // std::cout << "its double: " << fut.get() * 2 << '\n';

    return 0;
}
