/*
 @Date    : 2018-08-02 21:54:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    char d;
    int n;
    scanf("%c %d", &d, &n);
    char s[500000];
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            sprintf(s, "%c", d);
        }
        else
        {
            char last = s[0];
            int count = 0;
            string temp;
            char c;
            for (int j = 0; s[j]; ++j)
            {
                c = s[j];
                if (c == last)
                {
                    ++count;
                }
                else
                {
                    temp += last;
                    temp += to_string(count);

                    last = c;
                    count = 1;
                }
            }
            temp += last;
            temp += to_string(count);
            sprintf(s, "%s", temp.c_str());
        }
    }
    printf("%s\n", s);
    return 0;
}

