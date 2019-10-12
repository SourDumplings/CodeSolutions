/*
 @Date    : 2018-04-15 16:26:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.cnblogs.com/qicosmos/p/3534211.html
 */

#include <iostream>
#include <future>

using namespace std;

int main(int argc, char const *argv[])
{
    std::future<int> f1 = std::async(std::launch::async,
        []() -> int { cout << "f1" << endl; return 8; });

    cout << f1.get() << endl; //output: f1\n 8

    std::future<int> f2 = std::async(std::launch::async,
        []() -> int { cout << "f2" << endl; return 9; });

    f2.wait(); //output: f2

    std::future<int> f3 = std::async(std::launch::async,
        []() -> int
        {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << "f3" << endl;
            return 10;
        });

    std::cout << "waiting...\n";
    std::future_status status;
    do
    {
        status = f3.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::deferred)
        {
            std::cout << "deferred\n";
        }
        else if (status == std::future_status::timeout)
        {
            std::cout << "timeout\n";
        }
        else if (status == std::future_status::ready)
        {
            std::cout << "ready!\n";
        }
    } while (status != std::future_status::ready);

    std::cout << "result is " << f3.get() << '\n';
    return 0;
}

