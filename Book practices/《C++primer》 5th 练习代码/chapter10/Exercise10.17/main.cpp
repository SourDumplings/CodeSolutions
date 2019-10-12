/*
 @Date    : 2017-12-26 10:34:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p392
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
#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin("book_sales");
    Sales_data data;
    vector<Sales_data> v;
    while (fin)
    {
        read(fin, data);
        v.push_back(data);
    }
    stable_sort(v.begin(), v.end(), [](const Sales_data & d1, const Sales_data & d2) {return d1.isbn() < d2.isbn();});
    for (const auto &d : v)
    {
        print(cout, d);
    }
    return 0;
}

istream& read(istream& is, Sales_data& item)
{
    double p;
    is >> item.bookNo >> item.units_sold >> p;
    item.revenue = p * item.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << endl;
    return os;
}

Sales_data add(const Sales_data& l, const Sales_data& r)
{
    Sales_data sum = l;
    sum.combine(r);
    return sum;
}
