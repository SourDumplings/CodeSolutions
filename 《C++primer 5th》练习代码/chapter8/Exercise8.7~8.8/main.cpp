/*
 @Date    : 2017-12-19 19:23:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p320
在终端输入g++ -std=c++11 -o main main.cpp
先将main.cpp编译成main.exe
在cmd终端上运行 .\main book_sales results
便可得到results文件
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in(argv[1]);
    // ofstream out(argv[2]);
    ofstream out_a(argv[2], ofstream::app);
    Sales_data total(in);
    if (in)
    {
        Sales_data trans(in);
        do
        {
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(out_a, total);
                total = trans;
            }
        } while (read(in, trans));
        print(out_a, total);
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

