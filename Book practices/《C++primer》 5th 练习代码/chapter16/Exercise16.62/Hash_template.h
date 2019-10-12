/*
 @Date    : 2018-01-14 17:14:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p712
 */

#ifndef HASH_TEMPLATE_H
#define HASH_TEMPLATE_H

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

namespace std
{
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data&) const;
    };

    size_t hash<Sales_data>::operator()(const Sales_data &s) const
    {
        return hash<string>()(s.bookNo) ^
        hash<unsigned>()(s.units_sold) ^
        hash<double>()(s.revenue);
    }
}

#endif

