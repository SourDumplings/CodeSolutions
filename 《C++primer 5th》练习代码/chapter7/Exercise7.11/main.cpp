/*
 @Date    : 2017-12-19 19:23:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p266
输入：0-399-82477-1 3 45.39
得到结果：
d1:  0 0
d2: 0-201-82470-1 0 0
d3: 0-201-88954-4 5 60
d4: 0-399-82477-1 3 136.17
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data d1;
    Sales_data d2("0-201-82470-1");
    Sales_data d3("0-201-88954-4", 5, 12.00);
    Sales_data d4(cin);

    cout << "d1: ";
    print(cout, d1);
    cout << "d2: ";
    print(cout, d2);
    cout << "d3: ";
    print(cout, d3);
    cout << "d4: ";
    print(cout, d4);
    return 0;
}

istream& read(istream &is, Sales_data &item)
{
    double p;
    is >> item.bookNo >> item.units_sold >> p;
    item.revenue = p * item.units_sold;
    return is;
}

ostream& print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << endl;
    return os;
}

Sales_data add(const Sales_data &l, const Sales_data &r)
{
    Sales_data sum = l;
    sum.combine(r);
    return sum;
}

