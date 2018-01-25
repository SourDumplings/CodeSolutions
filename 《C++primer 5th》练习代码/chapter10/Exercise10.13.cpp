/*
 @Date    : 2017-12-25 21:45:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p387
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

using namespace std;

inline void out_put(const vector<string>::iterator begin, const vector<string>::iterator end)
{
    for (auto it = begin; it != end; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return;
}

bool five_or_more(const string &s)
{
    return s.size() >= 5;
}

int main(int argc, char const *argv[])
{
    string s = "fuckyou allthetime and Ilove you";
    istringstream sin(s);
    string word;
    vector<string> words;
    while (sin)
    {
        sin >> word;
        words.push_back(word);
    }
    out_put(words.begin(), words.end());

    auto it = partition(words.begin(), words.end(), five_or_more);

    out_put(words.begin(), it);
    return 0;
}
