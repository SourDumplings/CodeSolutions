/*
 @Date    : 2018-01-12 11:55:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p675
 */

#ifndef DEBUG_TEMPLATE_H
#define DEBUG_TEMPLATE_H

#include <iostream>

using namespace std;

class DebugDelete
{
private:
    ostream &os;
public:
    DebugDelete(ostream &s = cerr): os(s) {}
    template <typename T> void operator()(T* p)
    {
        os << "deleting pointer" << endl;
        delete p;
        return;
    }
};

#endif
