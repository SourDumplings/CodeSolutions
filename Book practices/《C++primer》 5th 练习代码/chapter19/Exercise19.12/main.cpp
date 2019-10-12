/*
 @Date    : 2018-01-24 11:15:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p838
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "Screen.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Screen::pos Screen::*pcursor = Screen::getCursor();
    Screen s(3, 5, '*');
    cout << s.*pcursor << endl;
    s.move(1, 2);
    cout << s.*pcursor << endl;
    return 0;
}
