/*
 @Date    : 2017-12-25 12:46:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p371
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "asd)sdad((sddfs(g)dsfs))asd";
    stack<char> S;
    int leftnum = 0;
    unsigned l = s.size();
    char c;
    for (unsigned i = 0; i < l; ++i)
    {
        if (leftnum)
        {
            if (s[i] == ')')
            {
                cout << s[i];
                do
                {
                    c = S.top();
                    cout << c;
                    S.pop();
                } while (c != '(' && !S.empty());
                --leftnum;
            }
            else
            {
                if (s[i] == '(')
                {
                    ++leftnum;
                }
                S.push(s[i]);
            }
        }
        else if (s[i] == '(')
        {
            ++leftnum;
            S.push(s[i]);
        }
    }
    return 0;
}
