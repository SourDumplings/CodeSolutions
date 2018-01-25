/*
 @Date    : 2017-12-17 20:15:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p188
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {0, 1, 1, 2}, v2 = {0, 1, 1, 2, 3, 5, 8};

    if (v1.size() > v2.size())
    {
        vector<int> temp;
        temp = v1;
        v1 = v2;
        v2 = temp;
    }

    int flag = 1;
    for (unsigned i = 0; i != v1.size(); ++i)
    {
        if (v1[i] != v2[i])
        {
            flag = 0;
            break;
        }
    }

    string j = flag ? "true" : "false";
    cout << j << endl;
    return 0;
}

