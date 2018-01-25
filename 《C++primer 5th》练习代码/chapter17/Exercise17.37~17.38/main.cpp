/*
 @Date    : 2018-01-18 19:36:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p764
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin("copyOut");
    char s[5];
    while (!fin.eof())
    {
        fin.getline(s, 10);
        cout << s;
        if (!fin.good() && !fin.eof())
            fin.clear();
        else
            cout << endl;
    }
    return 0;
}
