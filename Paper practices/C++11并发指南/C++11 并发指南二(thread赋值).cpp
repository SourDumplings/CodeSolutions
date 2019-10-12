/*
 @Date    : 2018-04-14 16:47:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3236136.html
 */

#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

void thread_task(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "hello thread "
              << std::this_thread::get_id()
              << " paused " << n << " seconds" << std::endl;
    return;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; i++)
    {
        threads[i] = std::move(std::thread(thread_task, i + 1));
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto &t : threads)
    {
        t.join();
    }
    std::cout << "All threads joined.\n";

    return EXIT_SUCCESS;

    return 0;
}  /* ----------  end of function main  ---------- */
