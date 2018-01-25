/*
 @Date    : 2018-01-08 19:04:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p611
 */

#include <iostream>
#include <string>
#include "my_quote.h"

using namespace std;

int main(int argc, char const *argv[])
{
    size_t num, minnum = 5;
    double price = 10, discount = 0.1;
    string isbn;
    cout << "input the isbn and the num you want to buy: ";
    cin >> isbn >> num;
    Quote q(isbn, price);
    Bulk_quote bq(isbn, price, minnum, discount);
    Limited_quote lq(isbn, price, minnum, discount);
    cout << "with no discount: ";
    print_total(cout, q, num);
    cout << "with bulk discount: ";
    print_total(cout, bq, num);
    cout << "with limited discount: ";
    print_total(cout, lq, num);
    return 0;
}
