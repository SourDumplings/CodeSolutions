/*
 @Date    : 2017-12-15 19:31:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p113
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        grade /= 10;
        auto it = scores.begin();
        (*(it + grade))++;
    }
    for (auto it = scores.cbegin(); it != scores.cend(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}

