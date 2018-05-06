/*
 @Date    : 2018-04-26 19:49:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
还是以宝马汽车制造为例。
　　随着客户的要求越来越高，宝马车需要不同配置的空调和发动机等配件。于是这个工厂开始生产空调和发动机，用来组装汽车。这时候工厂有两个系列的产品:空调和发动机。宝马320系列配置A型号空调和A型号发动机，宝马230系列配置B型号空调和B型号发动机。
抽象工厂模式是工厂方法模式的升级版本，他用来创建一组相关或者相互依赖的对象。比如宝马320系列使用空调型号A和发动机型号A，而宝马230系列使用空调型号B和发动机型号B，那么使用抽象工厂模式，在为320系列生产相关配件时，就无需制定配件的型号，它会自动根据车型生产对应的配件型号A。
 */

#include <iostream>
#include <cstdio>
#include <memory>
#include "FactoryBMW.h"

using namespace std;

// 客户端
int main(int argc, char const *argv[])
{
    shared_ptr<FactoryBMW> factoryBMW320(new FactoryBMW320);
    shared_ptr<Engine> engineA = factoryBMW320->create_engine();
    engineA->get_style_of_engine();
    shared_ptr<AirConditioner> airConditionerA = factoryBMW320->create_air_conditioner();
    airConditionerA->get_style_of_air_conditioner();

    cout << "........................." << endl;

    shared_ptr<FactoryBMW> factoryBMW523(new FactoryBMW523);
    shared_ptr<Engine> engineB = factoryBMW523->create_engine();
    engineB->get_style_of_engine();
    shared_ptr<AirConditioner> airConditionerB = factoryBMW523->create_air_conditioner();
    airConditionerB->get_style_of_air_conditioner();
    return 0;
}

