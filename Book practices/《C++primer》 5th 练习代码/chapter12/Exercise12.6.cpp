/*
 @Date    : 2017-12-29 21:30:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p463
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

vector<int>* new_vector(void)
{
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
    int v;
    while (cin >> v)
    {
        pv->push_back(v);
    }
    return;
}

void print_ints(vector<int> *pv)
{
    for (const auto &i : *pv)
    {
        cout << i << " ";
    }
    return;
}

int main(int argc, char const *argv[])
{
    vector<int> *pv = new_vector();
    if (!pv)
    {
        cout << "insufficient memory" << endl;
        return -1;
    }

    read_ints(pv);

    print_ints(pv);

    delete pv;
    pv = nullptr;

    return 0;
}
