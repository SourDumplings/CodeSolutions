/*
 @Date    : 2017-12-14 19:42:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p77
 */

#include <string>

#ifndef SALES_DATA_H
#define SALES_DATA_H

using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
