/*
 @Date    : 2017-12-28 14:29:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p426
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
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    string word;
    map<string, list<int>> word_lineno;
    ifstream fin("word_count");
    string line;
    int lineno = 0;
    while (getline(fin, line))
    {
        ++lineno;
        istringstream lin(line);
        while (lin >> word)
        {
            word_lineno[word].push_back(lineno);
        }
    }

    for (const auto &w : word_lineno)
    {
        cout << w.first << " is in line: ";
        for (const auto &i : w.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
