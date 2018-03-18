/*
 @Date    : 2018-02-02 14:19:26
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1061
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cctype>

using namespace std;

const array<string, 7> dayName{{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}};

int main(int argc, char const *argv[])
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int n1 = s1.length();
    string day;
    int hour;
    int first_pos;
    for (int i = 0; i != n1; ++i)
    {
        if ((s1[i] >= 'A' && s1[i] <= 'G') && (s1[i] == s2[i]))
        {
            day = dayName[s1[i] - 'A'];
            first_pos = i;
            break;
        }
    }
    for (int i = first_pos + 1; i != n1; ++i)
    {
        if (s1[i] == s2[i])
        {
            if (isdigit(s1[i]))
            {
                hour = s1[i] - '0';
                break;
            }
            else if (s1[i] >= 'A' && s1[i] <= 'N')
            {
                hour = s1[i] - 'A' + 10;
                break;
            }
        }
    }
    int min;
    int n3 = s3.length(), n4 = s4.length();
    for (int i = 0; i != n3 && i != n4; ++i)
    {
        if (isalpha(s3[i]) && s3[i] == s4[i])
        {
            min = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", day.c_str(), hour, min);
    return 0;
}
