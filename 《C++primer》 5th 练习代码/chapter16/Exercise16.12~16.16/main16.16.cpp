/*
 @Date    : 2018-01-11 21:45:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p668
 */

#include <iostream>
#include <string>
#include "Vec_template.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Vec<string> v({"123", "abc"});
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;
    cout << endl;

    return 0;
}
