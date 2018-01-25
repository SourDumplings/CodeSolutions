/*
 @Date    : 2017-12-11 09:31:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

// p11
// g++ -o Exercise1.7.cpp编译会出现错误信息：
// g++.exe: fatal error: no input files
// compilation terminated.
//  g++ -o Exercise Exercise1.7.cpp编译出现错误信息：
//  Exercise1.7.cpp:19:21: error: 'cannot' does not name a type
// * comment pairs/* */cannot nest.

#include <iostream>

/*
* comment pairs/* */cannot nest.
* "cannot nest" is considered source code,
* as is the rest of program
 */

int main()
{
    return 0;
}

