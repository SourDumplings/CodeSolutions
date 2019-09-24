/*
 @Date    : 2017-12-11 13:45:22
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
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
    {
        cout << item1 + item2 << endl;
        return 0;
    }
    else
    {
        cout << "Data must refer to same ISBN" << endl;
        return -1;
    }
}

