/*
 @Date    : 2017-12-28 11:32:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p422
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

string trans(string &word)
{
    for (unsigned i = 0; i < word.size(); ++i)
    {
        if (word[i] == ',' || word[i] == '.')
        {
            word.erase(i, 1);
        }
        else
        {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}

int main(int argc, char const *argv[])
{
    map<string, size_t> word_count;
    string word;
    ifstream fin("word_count");
    while (fin >> word)
    {
        ++word_count[trans(word)];
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}
