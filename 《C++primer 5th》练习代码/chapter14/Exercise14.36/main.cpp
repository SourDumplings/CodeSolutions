/*
 @Date    : 2018-01-06 14:23:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p572
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "ReadString.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ReadString rs;
    vector<string> v;
    while (true)
    {
        string line = rs();
        if (!line.empty())
            v.push_back(line);
        else
            break;
    }
    for_each(v.begin(), v.end(), [] (const string & s) { cout << s << endl; });
    return 0;
}
