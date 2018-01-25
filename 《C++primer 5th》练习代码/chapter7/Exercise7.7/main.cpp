/*
 @Date    : 2017-12-19 19:23:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p262
在终端输入g++ -std=c++11 -o main main.cpp
先将main.cpp编译成mainexe
在cmd终端上运行 .\main <book_sales> results
即可得到results文件
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else
    {
        cout << "No books" << endl;
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

