/*
 @Date    : 2018-01-01 12:06:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p480
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
#include <utility>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    char *r = new char[10];
    unsigned l = 0;
    char c;
    while (cin.get(c))
    {
        if (isspace(c))
        {
            break;
        }
        r[l++] = c;
        if (l == 10)
        {
            cout << "full" << endl;
            break;
        }
    }

    cout << r << endl;

    r[l] = 0;
    cout << r << endl;

    r[l] = '0';
    cout << r << endl;

    delete [] r;
    return 0;
}
