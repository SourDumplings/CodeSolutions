/*
 @Date    : 2018-01-23 10:16:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p823
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "StrVec.h"

using namespace std;

int main(int argc, char const *argv[])
{
    StrVec vs({"hello", "world", "!"});
    for (auto it = vs.begin(); it != vs.end(); ++it)
        cout << *it << endl;
    return 0;
}
