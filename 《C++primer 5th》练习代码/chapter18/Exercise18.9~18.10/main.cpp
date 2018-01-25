/*
 @Date    : 2018-01-19 21:28:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p785
验证IO：
book1 5 10
book2 6 10
wrong isbns: left isbn(book1) right isbn(book2)
book1 5 10 book1 7 20
book2 3 10 book1 8 70
wrong isbns: left isbn(book2) right isbn(book1)
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2)
    {
        try
        {
            sum = item1 + item2;
        }
        catch (const isbn_mismatch &e)
        {
            cerr << e.what() << ": left isbn(" << e.left <<
            ") right isbn(" << e.right << ")" << endl;
        }
    }
    return 0;
}
