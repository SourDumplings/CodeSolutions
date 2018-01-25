/*
 @Date    : 2018-01-23 17:01:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p829
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "Complex_Query.h"
#include <typeinfo>

using namespace std;

int main(int argc, char const *argv[])
{
    Query_base *pqb = new Query_base;
    if (AndQuery *paq = dynamic_cast<AndQuery*>(pqb))
        cout << "dynamic_cast<AndQuery*>(pqb) success" << endl;
    else
        cout << "dynamic_cast<AndQuery*>(pqb) fail" << endl;

    Query_base &rqb = *pqb;
    try
    {
        AndQuery paq = dynamic_cast<AndQuery&>(rqb);
        cout << "dynamic_cast<AndQuery&>(rqb) success" << endl;
    }
    catch (bad_cast)
    {
        cout << "dynamic_cast<AndQuery&>(rqb) fail" << endl;
    }

    Query_base *pqb1 = new Query_base, *pqb2 = new Query_base;
    if (typeid(*pqb1) == typeid(*pqb2))
        cout << "they point to the same type" << endl;
    else
        cout << "they don't point to the same type" << endl;

    return 0;
}
