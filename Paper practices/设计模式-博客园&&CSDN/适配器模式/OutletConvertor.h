/*
 @Date    : 2018-05-02 13:43:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
转接头类，即类适配器
 */

#ifndef OUTLET_CONVERTOR_H
#define OUTLET_CONVERTOR_H

#include "ThreePhaseOutlet.h"
#include "TwoPhaseOutlet.h"

class OutletConvertor: public ThreePhaseOutlet, public TwoPhaseOutlet
{
public:
    virtual ~OutletConvertor() = default;
    void do_plugin() override
    {
        do_converter();
        do_three_phase_plugin();
        return;
    }
    void do_converter()
    {
        cout << "三相插头转为两相插头" << endl;
        return;
    }
};

#endif // OUTLET_CONVERTOR_H


