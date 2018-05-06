/*
 @Date    : 2018-05-02 14:37:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
比如你在网上买了一个手机，但是买家给你发回来了一个3接头的充电器，
但是恰好你又没有3接头的插槽，只有2个接口的插槽，
于是你很直然地便会想到去找你个3接口转两接口的转换器。
简单的分析下这个转换器便是我们这里的适配器Adapter。三相插头便是我们要适配的Adaptee
 */

#include <iostream>
#include <cstdio>
#include <memory>

#include "TwoPhaseOutlet.h"
#include "ThreePhaseOutlet.h"
#include "OutletConvertor.h"
#include "OutletConvertor2.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // shared_ptr<TwoPhaseOutlet> outlet(new OutletConvertor);
    shared_ptr<TwoPhaseOutlet> outlet(new OutletConvertor2(ThreePhaseOutlet()));
    outlet->do_plugin();

    return 0;
}

