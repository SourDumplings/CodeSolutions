/*
 @Date    : 2018-04-13 12:48:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3235560.html
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream> // std::cout
#include <thread>   // std::thread

void thread_task()
{
    std::cout << "hello thread" << std::endl;
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
    std::thread t(thread_task);
    t.join();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
