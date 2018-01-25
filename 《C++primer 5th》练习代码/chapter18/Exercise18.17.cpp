/*
 @Date    : 2018-01-21 11:48:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p796
 */

#include <iostream>
#include <cstdio>

using namespace std;

namespace Exercise
{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;

// pos1

// using Exercise::ivar;
// using Exercise::dvar;
// using Exercise::limit;
//
using namespace Exercise;

void manip()
{
    // pos2
    // using Exercise::ivar;
    // using Exercise::dvar;
    // using Exercise::limit;

    // using namespace Exercise;


    double dvar = 3.14;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
    printf("dvar = %f, iobj = %d, ivar = %d, ::ivar = %d\n", dvar, iobj, ivar, ::ivar);
    return;
}

int main(int argc, char const *argv[])
{
    manip();
    return 0;
}
