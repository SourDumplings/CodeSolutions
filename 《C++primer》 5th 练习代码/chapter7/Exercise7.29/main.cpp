/*
 @Date    : 2017-12-20 20:17:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p278
 */

#include <iostream>
#include <string>
#include "Screen.h"

using namespace std;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    return 0;
}

