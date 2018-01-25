/*
 @Date    : 2017-12-11 14:45:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p25
 */

#include <iostream>
#include <cstdio>
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item total;
    if (cin >> total)
    {
        Sales_item trans;
        while (cin >> trans)
        {
            if (trans.isbn() == total.isbn())
            {
                total += trans;
            }
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }
    else
    {
        cout << "No data?!" << endl;
        return -1;
    }
    return 0;
}

