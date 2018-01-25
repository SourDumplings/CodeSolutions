/*
 @Date    : 2017-12-11 18:12:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p38
输出结果为：
32
4294967264
32
-32
0
0
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl;
    int i = 10, i2 = 42;
    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;
    return 0;
}

