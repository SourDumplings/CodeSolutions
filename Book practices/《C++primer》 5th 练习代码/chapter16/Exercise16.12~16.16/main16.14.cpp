/*
 @Date    : 2018-01-11 20:32:07
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
    Screen<5, 3> myScreen;
    myScreen.display(cout);
    cout << endl;
    myScreen.move(4, 0).set('#');

    Screen<5, 5> nextScreen('X');
    nextScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    nextScreen.display(cout);
    cout << endl;

    const Screen<5, 3> blank;
    myScreen.set('#').display(cout);
    cout << endl;
    blank.display(cout);
    cout << endl;

    myScreen.clear('Z').display(cout);
    cout << endl;
    myScreen.move(4, 0);
    myScreen.set('#');
    myScreen.display(cout);
    cout << endl;
    myScreen.clear('Z').display(cout);
    cout << endl;

    Screen<5, 3> temp = myScreen.move(4, 0);
    temp.set('#');
    myScreen.display(cout);
    cout << endl;

    return 0;
}
