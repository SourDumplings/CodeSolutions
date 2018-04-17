/*
 @Date    : 2018-04-15 13:25:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
共用体
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Test
{
    int i;
    double pi;
    char str[10];
};

int main(int argc, char const *argv[])
{
    union Test test;

    test.i = 520;
    test.pi = 3.14;
    strcpy(test.str, "Hello");

    printf("addr of test.i = %p\n", &test.i);
    printf("addr of test.pi = %p\n", &test.pi);
    printf("addr of test.str = %p\n", &test.str);

    printf("test.i = %d\n", test.i);
    printf("test.pi = %f\n", test.pi);
    printf("test.str = %s\n", test.str);

    printf("%u\n", sizeof(test));
    return 0;
}
