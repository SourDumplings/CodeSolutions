/*
 @Date    : 2017-12-11 13:53:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p22
 */

#include <iostream>
#include <cstdio>
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item item1, item2;
    cin >> item1;
    while (cin >> item2)
    {
        if (item1.isbn() == item2.isbn())
        {
            item1 += item2;
        }
        else
        {
            cout << "Data must refer to same ISBN" << endl;
            return -1;
        }
    }
    cout << item1 << endl;
    return 0;
}

