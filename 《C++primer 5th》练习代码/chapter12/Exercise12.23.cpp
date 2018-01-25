/*
 @Date    : 2018-01-01 11:58:58
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
#include <cstring>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    const char *c1 = "Hello";
    const char *c2 = "World";
    char *r = new char[strlen(c1) + strlen(c2)];
    strcpy(r, c1);
    strcat(r, c2);
    cout << r << endl;

    string s1("Hello");
    string s2("World");
    string s = s1 + s2;
    strcpy(r, (s1+s2).c_str());
    cout << r << endl;

    delete [] r;
    return 0;
}
