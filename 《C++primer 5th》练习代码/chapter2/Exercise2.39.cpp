/*
 @Date    : 2017-12-14 18:31:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p74
无法编译通过，得到错误信息：
g++: fatal error: no input files
compilation terminated.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Foo {} // no semicolon

int main()
{
    return 0;
}

