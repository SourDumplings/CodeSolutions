/*
 @Date    : 2017-12-18 12:47:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p208
使用命令：
g++ -std=c++11 factMain.cpp fact.cpp -o main.exe
进行分离式编译，得到main.exe，实现一个数的阶乘
 */

#include <iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}

