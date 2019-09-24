/*
 @Date    : 2018-01-06 15:50:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p574
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StrLenIs
{
private:
    size_t len;
public:
    StrLenIs(int l): len(l) {}
    bool operator()(const string &s) { return s.length() == len; }
};

void readStr(istream &is, vector<string> &v)
{
    string word;
    while (is >> word)
        v.push_back(word);
    return;
}

int main(int argc, char const *argv[])
{
    vector<string> v;
    readStr(cin, v);
    const int minLen = 1;
    const int maxLen = 10;
    for (int i = minLen; i <= maxLen; ++i)
    {
        StrLenIs slenIs(i);
        cout << "len:" << i << ", cnt: " <<
        count_if(v.begin(), v.end(), slenIs) << endl;
    }
    return 0;
}
