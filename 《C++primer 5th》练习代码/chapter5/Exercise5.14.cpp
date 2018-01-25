/*
 @Date    : 2017-12-17 15:44:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p185
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    string s;
    while (cin >> s)
    {
        v.push_back(s);
    }
    int maxrepeat = 0;
    int cnt = 1;
    string maxrepeatword;
    for (unsigned i = 0; i != v.size() - 1; ++i)
    {
        if (v[i] == v[i+1])
        {
            cnt++;
        }
        else
        {
            if (cnt > maxrepeat)
            {
                maxrepeat = cnt;
                maxrepeatword = v[i];
                cnt = 1;
            }
        }
    }
    cout << maxrepeatword << " repeats for the most time " << maxrepeat << endl;
    return 0;
}

