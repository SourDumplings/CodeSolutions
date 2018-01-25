/*
 @Date    : 2017-12-25 11:09:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p369
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>

using namespace std;

array<string, 12> m{"January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"};

class Date
{
public:
    unsigned year, month, day;
    Date() = default;
    Date(string);
};

Date::Date(string date)
{
    unsigned posback;
    if ((posback = date.find('/')) != string::npos)
    {
        month = stoi(date.substr(0, posback));
        unsigned temp = posback;
        posback = date.find('/', posback+1);
        day = stoi(date.substr(temp+1, posback-temp-1));
        year = stoi(date.substr(posback+1));
    }
    else
    {
        unsigned posspace = date.find(" ");
        string mon = date.substr(0, posspace);
        for (unsigned i = 0; i < 12; ++i)
        {
            if (m[i] == mon || m[i].substr(0, 3) == mon)
            {
                month = i + 1;
                break;
            }
        }
        unsigned poscomma = date.find(",", posspace);
        day = stoi(date.substr(posspace+1, poscomma-posspace-1));
        year = stoi(date.substr(poscomma+2));
    }
}

void print(Date d)
{
    printf("%d%02d%02d\n", d.year, d.month, d.day);
    return;
}

int main(int argc, char const *argv[])
{
    Date d;
    d = {"January 1, 1990"};
    print(d);
    d = {"1/1/1990"};
    print(d);
    d = {"Feb 23, 2017"};
    print(d);
    return 0;
}
