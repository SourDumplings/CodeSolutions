/*
 @Date    : 2017-12-18 15:37:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p220
先编译成exe文件： g++ -std=c++11 -o Exercise6.26.exe Exercise6.26.cpp
再再执行时输入命令行参数：.\Exercise6.26 abs iloveyou 2323d
得到结果：
abs
iloveyou
2323d
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}

