/*
 @Date    : 2018-05-02 15:25:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
转接头类-对象适配器
 */

#ifndef OUTLET_CONVERTOR2_H
#define OUTLET_CONVERTOR2_H

#include "TwoPhaseOutlet.h"
#include "ThreePhaseOutlet.h"

class OutletConvertor2: public TwoPhaseOutlet
{
public:
    OutletConvertor2(const ThreePhaseOutlet &out_): m_out(out_) {}
    OutletConvertor2(ThreePhaseOutlet &&out_): m_out(out_) {}
    virtual ~OutletConvertor2() = default;
    void do_plugin()
    {
        do_convertor();
        m_out.do_three_phase_plugin();
        return;
    }
    void do_convertor()
    {
        cout << "三相插头转为两相插头！" << endl;
        return;
    }
    ThreePhaseOutlet m_out;
};

#endif // OUTLET_CONVERTOR2_H


