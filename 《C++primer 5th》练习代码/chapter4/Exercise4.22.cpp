/*
 @Date    : 2017-12-16 16:24:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p152
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int G[14] = {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
    for (auto g : G)
    {
        // string s;
        // if (g > 90)
        // {
        //     s = "high pass";
        // }
        // else if (g < 60)
        // {
        //     s = "fail";
        // }
        // else if (g < 75)
        // {
        //     s = "low pass";
        // }
        // else
        // {
        //     s = "pass";
        // }
        // cout << s << endl;
        cout << (g < 60 ? "fail" : (g > 90 ? "high pass" : (g < 75 ? "low pass" : "pass"))) << endl;
    }
    return 0;
}

