/*
 @Date    : 2017-12-15 21:05:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p124
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    char s1[10] = "Hello", s2[10] = "World", s3[8];
    cout << strlen(s1) << endl;
    strcpy(s3, s1);
    strcat(s3, s2);
    puts(s3);
    return 0;
}

