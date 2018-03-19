/*
 @Date    : 2018-03-19 13:44:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1153
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int l1 = s1.length(), l2 = s2.length();
        bool ok = false;
        if (l1 == l2)
        {
            for (unsigned i = 0; i < l1; ++i)
            {
                if (s1[i] == s2[0])
                {
                    // printf("%c\n", s1[i]);
                    // printf("%s %s %s %s\n", s2.substr(l1 - i).c_str(), s1.substr(0, i).c_str(),
                    //     s2.substr(i).c_str(), s2.substr(0, l1 - i).c_str());
                    if (s2.substr(l1 - i) == s1.substr(0, i) &&
                        s1.substr(i) == s2.substr(0, l1 - i))
                    {
                        ok = true;
                        break;
                    }
                }
            }
        }
        if (ok)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}

