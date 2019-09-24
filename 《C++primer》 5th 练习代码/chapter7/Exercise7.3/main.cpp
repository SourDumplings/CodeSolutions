/*
 @Date    : 2017-12-19 19:23:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p260
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
    double p;
    if (cin >> total.bookNo >> total.units_sold >> p)
    {
        total.revenue = p * total.units_sold;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> p)
        {
            trans.revenue = trans.units_sold * p;
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        cout << "No books" << endl;
    }
    return 0;
}

