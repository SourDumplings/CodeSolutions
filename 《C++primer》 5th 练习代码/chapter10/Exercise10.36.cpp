/*
 @Date    : 2017-12-27 21:00:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p410
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
    list<int> l{1, 2, 0, 1, 2, 0, 1, 2};
    auto last_z = find(l.rbegin(), l.rend(), 0);
    printf("last_z points to %d\n", *last_z);
    printf("last_z.base() points to %d\n", *last_z.base());
    printf("This is No.%d number in l.\n",
        count_if(l.begin(), last_z.base(), [] (const int i) {return true;}));
    return 0;
}
