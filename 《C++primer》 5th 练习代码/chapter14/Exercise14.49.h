/*
 @Date    : 2018-01-07 10:52:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p583
 */

#include <iostream>
#include <array>

using namespace std;

class Date
{
    friend bool operator==(const Date&, const Date&);
private:
    int year, month, day;
    static constexpr array<array<int, 12>, 2> days_of_month
    {{
        {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}},
        {{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}
    }};
public:
    explicit operator bool();
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}
    friend ostream& operator<<(ostream&, const Date&);
};

constexpr array<array<int, 12>, 2> Date::days_of_month;

Date::operator bool()
{
    bool isLeapYear = (year % 4 == 0 && year % 100) || year % 400 == 0;
    bool valid;
    if (month <= 12 && month >= 1 &&
        day >= 1 && day <= 31)
    {
        if (isLeapYear)
            valid = day <= days_of_month[1][month-1];
        else
            valid = day <= days_of_month[0][month-1];
    }
    else
        valid = false;
    return valid;
}

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

