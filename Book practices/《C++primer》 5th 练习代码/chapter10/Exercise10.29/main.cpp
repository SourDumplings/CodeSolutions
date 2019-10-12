/*
 @Date    : 2017-12-27 19:35:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p407
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

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    ifstream fin("readme");
    istream_iterator<string> itin(fin), eof;
    vector<string> v(itin, eof);
    ostream_iterator<string> itout(cout, " ");
    copy(v.begin(), v.end(), itout);
    cout << endl;
    return 0;
}
