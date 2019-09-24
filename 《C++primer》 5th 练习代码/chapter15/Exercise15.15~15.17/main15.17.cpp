/*
 @Date    : 2018-01-08 19:12:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p611
得到编译错误信息：
main15.17.cpp: In function 'int main(int, const char**)':
main15.17.cpp:16:16: error: cannot declare variable 'd' to be of abstract type 'Disc_quote'
     Disc_quote d;
                ^
In file included from main15.17.cpp:12:0:
my_quote.h:42:7: note:   because the following virtual functions are pure within 'Disc_quote':
 class Disc_quote: public Quote
       ^
my_quote.h:51:12: note:         virtual double Disc_quote::net_price(size_t) const
     double net_price(size_t) const = 0;
            ^
 */

#include "my_quote.h"

int main(int argc, char const *argv[])
{
    Disc_quote d;
    return 0;
}
