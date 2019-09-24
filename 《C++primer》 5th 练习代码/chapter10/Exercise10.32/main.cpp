/*
 @Date    : 2017-12-26 19:34:34
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
#include "Sales_item.h"

using namespace std;

bool cmp(const Sales_item &d1, const Sales_item &d2)
{
    return d1.isbn() < d2.isbn();
}

int main(int argc, char const *argv[])
{
    ifstream fin("book_sales");
    Sales_item data;
    vector<Sales_item> v;
    istream_iterator<Sales_item> in(fin), eof;
    while(in != eof)
    {
        v.push_back(*in++);
    }
    sort(v.begin(), v.end(), cmp);
    vector<Sales_item>::iterator first = v.begin(), last;
    while (first != v.end())
    {
        last = find_if(first + 1, v.end(),
        [first] (const Sales_item & next_data) {return next_data.isbn() != (*first).isbn();});
        cout << accumulate(first+1, last, *first) << endl;
        first = last;
    }
    return 0;
}
