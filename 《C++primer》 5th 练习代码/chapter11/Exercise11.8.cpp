/*
 @Date    : 2017-12-28 14:04:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p424
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
    vector<string> v;
    string word;
    while (cin >> word)
    {
        if (find(v.begin(), v.end(), word) == v.end())
        {
            v.push_back(word);
        }
        cout << "v now contains: ";
        for_each(v.begin(), v.end(), [] (const string &s) {cout << s << " ";});
    }
    return 0;
}
