/*
 @Date    : 2017-12-21 14:37:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p294
 */

#include <iostream>

using namespace std;

class NoDefault
{
public:
    NoDefault(int) {}
};

class C
{
    NoDefault member;
public:
    C(int i = 0) : member(i) {}
};
