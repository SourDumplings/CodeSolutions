/*
 @Date    : 2017-12-17 15:08:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p178
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grades[14] = {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
    string lettergrade;
    for (int grade : grades)
    {
        lettergrade = grade < 60 ? scores[0] : scores[(grade-50)/10];
        cout << lettergrade << endl;
    }
    return 0;
}

