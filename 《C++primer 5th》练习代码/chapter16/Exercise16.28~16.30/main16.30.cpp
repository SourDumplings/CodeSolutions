/*
 @Date    : 2018-01-12 16:49:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p678
 */

#include <iostream>
#include <string>
#include "my_Blob_template.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Blob<string> b1;
    cout << b1.size() << endl;
    {
        Blob<string> b2{"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b1.size() << " " << b2.size() << endl;
    }
    cout << b1.size() << endl;
    for (size_t i = 0; i != b1.size(); ++i)
        cout << b1[i] << " ";
    cout << endl << endl;

    UP<int> u1(new int(42));
    cout << *u1 << endl;
    UP<int> u2(u1.release());
    cout << *u2 << endl;

    return 0;
}
