/*
 @Date    : 2017-12-14 19:45:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p77
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data data1, data2;
    double price = 0;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt
            << " " << totalRevenue << " ";
        if (totalCnt != 0)
        {
            cout << totalRevenue/totalCnt << endl;
        }
        else
        {
            cout << "No sales" << endl;
        }
        return 0;
    }
    else
    {
        cout << "Data must refer to the game ISBN"
            << endl;
        return -1;
    }
    return 0;
}

