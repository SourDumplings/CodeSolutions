/*
 @Date    : 2018-04-26 20:10:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
工厂类
 */

#ifndef FACTORY_BMW_H
#define FACTORY_BMW_H

#include <iostream>
#include <memory>

#include "Engine.h"
#include "AirConditioner.h"

using namespace std;

// 工厂抽象类
class FactoryBMW
{
public:
    virtual ~FactoryBMW() = default;
    virtual shared_ptr<Engine> create_engine() = 0;
    virtual shared_ptr<AirConditioner> create_air_conditioner() = 0;
};

// 工厂具体类
class FactoryBMW320: public FactoryBMW
{
public:
    ~FactoryBMW320() override = default;
    shared_ptr<Engine> create_engine()
    {
        return shared_ptr<Engine>(new EngineA);
    }
    shared_ptr<AirConditioner> create_air_conditioner()
    {
        return shared_ptr<AirConditioner>(new AirConditionerA);
    }
};

class FactoryBMW523: public FactoryBMW
{
public:
    ~FactoryBMW523() override = default;
    shared_ptr<Engine> create_engine()
    {
        return shared_ptr<Engine>(new EngineB);
    }
    shared_ptr<AirConditioner> create_air_conditioner()
    {
        return shared_ptr<AirConditioner>(new AirConditionerB);
    }
};

#endif // FACTORY_BMW_H



