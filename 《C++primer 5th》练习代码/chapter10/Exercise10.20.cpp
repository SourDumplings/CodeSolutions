/*
 @Date    : 2017-12-27 12:04:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p397
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

int main(int argc, char const *argv[])
{
    vector<string> words{"sdjhkja", "adsda", "asdadad", "asd", "weiudhiun"};
    cout << count_if(words.begin(), words.end(), [](const string & s) {return s.size() > 6;}) << endl;
    return 0;
}
