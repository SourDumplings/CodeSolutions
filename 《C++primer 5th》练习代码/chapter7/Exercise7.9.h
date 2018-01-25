/*
 @Date    : 2017-12-19 20:30:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p260
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person
{
    string name;
    string address;
    string get_name(void) const {return name;};
    string get_addr(void) {return address;};
};

istream& read(istream&, Person&);
ostream& print(ostream&, const Person&);

#endif

