/*
 @Date    : 2018-05-02 13:41:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
两相插头类
 */

#ifndef TWO_PHASE_OUTLET_H
#define TWO_PHASE_OUTLET_H

#include <iostream>

using namespace std;

class TwoPhaseOutlet
{
public:
    virtual ~TwoPhaseOutlet() = default;
    virtual void do_plugin() = 0;
};

#endif // TWO_PHASE_OUTLET_H


