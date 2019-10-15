/*
 @Date    : 2018-04-15 17:39:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
枚举值的指定
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // enum Color { RED = 10, GREEN, BLUE };
    // enum Color rgb;
    // for (rgb = RED; rgb <= BLUE; ++rgb)
    // {
    //     printf("rgb is %d\n", rgb);
    // }

    /* 枚举常量中间的赋值
    打印结果为：
    RED = 0
    GREEN = 1
    BLUE = 10
    YELLOW = 11 */
    enum Color { RED, GREEN, BLUE = 10, YELLOW };
    printf("RED = %d\n", RED);
    printf("GREEN = %d\n", GREEN);
    printf("BLUE = %d\n", BLUE);
    printf("YELLOW = %d\n", YELLOW);
    return 0;
}
