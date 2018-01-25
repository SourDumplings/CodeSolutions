/*
 @Date    : 2017-12-11 14:14:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p24
 */

#include <iostream>
#include <cstdio>
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item item1, item2;
    cin >> item1;
    int num = 1;
    while (cin >> item2)
    {
        if (item1.isbn() == item2.isbn())
        {
            item1 += item2;
            num++;
        }
        else
        {
            cout << "There are " << num << " records of " << item1.isbn() << endl;
            num = 1;
            item1 = item2;
        }
    }
    cout << "There are " << num << " records of " << item1.isbn() << endl;
    return 0;
}

