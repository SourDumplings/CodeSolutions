/*
 @Date    : 2018-04-25 10:05:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
潘金莲和贾氏的类实现
 */

#include <iostream>
#include "RealSubject.h"

using namespace std;

Panjinlian::Panjinlian() {};

Panjinlian::~Panjinlian() {};

void Panjinlian::makeEyesWithMan()
{
    cout << "Panjinlian leer at ogle to man." << endl;
    return;
}

void Panjinlian::makeLoveWithMan()
{
    cout << "Panjinlian is making love with someone." << endl;
    return;
}

Jiashi::Jiashi() {}

Jiashi::~Jiashi() {}

void Jiashi::makeEyesWithMan()
{
    cout << "Jiashi leer at ogle to man." << endl;
    return;
}

void Jiashi::makeLoveWithMan()
{
    cout << "Jiashi is making love with someone." << endl;
    return;
}

