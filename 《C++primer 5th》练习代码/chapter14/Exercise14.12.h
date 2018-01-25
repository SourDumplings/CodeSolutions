/*
 @Date    : 2018-01-05 16:54:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p560
 */

#include <iostream>

using namespace std;

class Date
{
private:
    int year, month, day;
public:
    friend istream& operator>>(istream&, Date&);
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}
    friend ostream& operator<<(ostream&, const Date&);
};

istream& operator>>(istream &is, Date &d)
{
    is >> d.year >> d.month >> d.day;
    if (!is)
        d = Date(0, 0, 0);
    return is;
}

ostream& operator<<(ostream &os, const Date &d)
{
    const char sep = '\t';
    os << "year" << d.year << sep << "month:" << d.month <<
       sep << d.day << endl;
    return os;
}
