/*
 @Date    : 2018-01-11 21:07:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p668
 */

#include <iostream>
#include "Screen_template.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Screen<3, 3> myScreen('#');
    myScreen.display(cout);
    cout << endl;
    cout << myScreen << endl;

    cin >> myScreen;
    myScreen.display(cout);
    cout << endl;
    cout << myScreen << endl;

    return 0;
}
