/*
 @Date    : 2018-01-12 20:38:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p681
 */

#include <iostream>

using namespace std;

template <typename T> T calc(T, int) {};
template <typename T> T fcn(T, T) {};

int main(int argc, char const *argv[])
{
    double d;
    float f;
    char c;

    calc(c, 'c');
    calc(d, f);
    fcn(c, 'c');
    // fcn(d, f);
    return 0;
}
