/*
 @Date    : 2018-01-14 12:23:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p706
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "my_Smart_Pointer.h"
#include "my_Blob_template.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vs{"Hello", "World", "!"};
    Blob<string> b3{vs.begin(), vs.end()};
    cout << b3.size() << endl;
    for (size_t i = 0; i < b3.size(); ++i)
        cout << b3[i] << " ";
    cout << endl << endl;

    string as[3] = {"This", "is", "end"};
    Blob<string> b4{as, as+3};
    cout << b4.size() << endl;
    for (size_t i = 0; i < b4.size(); ++i)
        cout << b4[i] << " ";
    cout << endl << endl;
    return 0;
}
