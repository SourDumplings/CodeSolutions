/*
 @Date    : 2017-12-18 12:49:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p109
 */

#include "Chapter6.h"

unsigned fact(int n)
{
    int r = 1;
    while (n)
    {
        r *= n--;
    }
    return r;
}
