/*
 @Date    : 2017-12-18 10:49:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p206
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

unsigned count_calls(void)
{
    static unsigned call_cnt = 0;
    return ++call_cnt;
}

int main()
{
    for (unsigned i = 0; i != 10; ++i)
    {
        cout << "The funcition has been called for " << count_calls() << " times." << endl;
    }
    return 0;
}

