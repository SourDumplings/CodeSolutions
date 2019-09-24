/*
 @Date    : 2018-01-05 14:57:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p556
 */

#include <iostream>

using namespace std;

class Date
{
private:
    int year, month, day;
public:
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}
    friend ostream& operator<<(ostream&, const Date&);
};

ostream& operator<<(ostream &os, const Date &d)
{
    const char sep = '\t';
    os << "year" << d.year << sep << "month:" << d.month <<
    sep << d.day << endl;
    return os;
}
