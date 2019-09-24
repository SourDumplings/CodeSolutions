/*
 @Date    : 2017-12-31 16:11:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p476
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
#include "my_StrBlob.h"

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    ifstream fin(argv[1]);
    if (!fin)
    {
        cout << "cannot open this file" << endl;
        return -1;
    }

    StrBlob b;
    string s;
    while (getline(fin, s))
    {
        b.push_back(s);
    }

    for (auto it = b.begin(); neq(it, b.end()); it.incr())
    {
        cout << it.deref() << endl;
    }
    return 0;
}
