/*
 @Date    : 2017-12-28 10:01:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p416
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

int main(int argc, char const *argv[])
{
    list<string> l{"I", "love", "love", "I", "you", "you", "you"};
    l.sort();
    l.unique();
    for (auto s : l)
    {
        cout << s << endl;
    }
    return 0;
}
