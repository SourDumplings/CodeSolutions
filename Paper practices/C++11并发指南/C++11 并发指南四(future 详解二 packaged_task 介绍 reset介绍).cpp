/*
 @Date    : 2018-04-15 12:57:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3279565.html
 */

#include <iostream>     // std::cout
#include <utility>      // std::move
#include <future>       // std::packaged_task, std::future
#include <thread>       // std::thread

// a simple task:
int triple (int x) { return x*3; }

int main ()
{
    std::packaged_task<int(int)> tsk (triple); // package task


    std::future<int> fut = tsk.get_future();
    tsk(100);
    std::cout << "The triple of 100 is " << fut.get() << ".\n";


    // re-use same task object:
    tsk.reset();
    fut = tsk.get_future();
    std::thread(std::move(tsk), 200).detach();
    std::cout << "Thre triple of 200 is " << fut.get() << ".\n";

    return 0;
}
