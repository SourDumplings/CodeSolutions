/*
 @Date    : 2017-12-27 11:04:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p392
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

bool cmp(const string &a, const string &b)
{
    bool result = false;
    if (a.size() < b.size() || (a.size() == b.size() && a < b))
    {
        result = true;
    }
    return result;
}

string make_plural(unsigned count, const string &word, const string &suffix)
{
    if (count > 1)
    {
        return word + suffix;
    }
    else
    {
        return word;
    }
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    auto wc = partition(words.begin(), words.end(), [sz](const string & a) {return a.size() >= sz;});
    sort(words.begin(), wc, cmp);
    words.erase(unique(words.begin(), wc), words.end());
    auto count = words.end() - words.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), words.end(), [](const string & s) {cout << s << " ";});
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    vector<string> words{"I", "love", "you", "and", "fuck", "you", "all", "the", "time",
                         "and", "shit", "you", "all", "around", "of", "your", "body"};
    unsigned size = 3;
    biggies(words, size);
    return 0;
}
