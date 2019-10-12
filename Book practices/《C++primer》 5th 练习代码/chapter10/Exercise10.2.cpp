/*
 @Date    : 2017-12-25 15:05:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p378
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
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
    list<string> l;
    string word;
    while (cin >> word)
    {
        l.push_back(word);
    }
    cout << "input the value you want to count for: ";
    cin.clear();
    cin >> word;
    cout << count(l.begin(), l.end(), word) << endl;
    return 0;
}
