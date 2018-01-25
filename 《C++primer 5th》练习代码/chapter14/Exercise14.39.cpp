/*
 @Date    : 2018-01-06 15:57:44
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

class StrLenBetWeen
{
private:
    size_t minLen, maxLen;
public:
    StrLenBetWeen(int min, int max): minLen(min), maxLen(max) {}
    bool operator()(const string &s) { return s.length() >= minLen && s.length() <= maxLen; }
};

class StrLenNoUnder
{
private:
    size_t minLen;
public:
    StrLenNoUnder(int min): minLen(min) {}
    bool operator()(const string &s) { return s.length() >= minLen; }
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
    StrLenBetWeen b(1, 9);
    StrLenNoUnder n(10);
    vector<string> v;
    readStr(cin, v);
    cout << "len 1~9: " << count_if(v.begin(), v.end(), b) << endl;
    cout << "len >= 10: " << count_if(v.begin(), v.end(), n) << endl;
    return 0;
}
