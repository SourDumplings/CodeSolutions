/*
 @Date    : 2018-01-14 17:03:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p712
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "Sales_data.h"
#include "Hash_template.h"

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_multiset<Sales_data> SDset{{"book1", 5, 20}, {"book2", 5, 20}, {"book1", 5, 20},
    {"book1", 10, 9}};
    SDset.insert({"book1", 3, 7});
    for (const auto &s : SDset)
    {
        cout << s << endl;
    }
    return 0;
}
