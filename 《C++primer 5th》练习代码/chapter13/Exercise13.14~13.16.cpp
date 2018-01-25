/*
 @Date    : 2018-01-02 16:57:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p506
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

class numbered
{
    static int seq;
public:
    int mysn;
    numbered() { mysn = seq++; }
    // numbered(const numbered& n) { mysn = seq++; }
};

int numbered::seq = 0;

void f(numbered s) { cout << s.mysn << endl; }
// void f(const numbered &s) { cout << s.mysn << endl; }

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = a;
    f(a);
    f(b);
    f(c);
    return 0;
}
