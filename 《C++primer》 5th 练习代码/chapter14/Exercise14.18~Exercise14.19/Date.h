/*
 @Date    : 2018-01-05 19:52:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p562
 */

#include <iostream>

using namespace std;

class Date
{
    friend bool operator==(const Date&, const Date&);
private:
    int year, month, day;
public:
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}
    friend ostream& operator<<(ostream&, const Date&);
};

bool operator==(const Date &d1, const Date &d2)
{
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator!=(const Date &d1, const Date &d2)
{
    return !(d1 == d2);
}

ostream& operator<<(ostream &os, const Date &d)
{
    const char sep = '\t';
    os << "year" << d.year << sep << "month:" << d.month <<
    sep << d.day << endl;
    return os;
}
