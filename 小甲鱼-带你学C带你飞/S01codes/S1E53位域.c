/*
 @Date    : 2018-04-16 14:41:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
位域
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    struct Test
    {
        unsigned int a: 1;
        unsigned int b: 1;
        unsigned int c: 2;
    };

    struct Test test;

    test.a = 0;
    test.b = 1;
    test.c = 2;

    printf("a = %d, b = %d, c = %d\n", test.a, test.b, test.c);
    printf("size of test = %d\n", sizeof(test));
    return 0;
}
