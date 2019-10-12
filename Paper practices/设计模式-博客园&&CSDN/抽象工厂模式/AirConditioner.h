/*
 @Date    : 2018-04-26 20:09:01
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
空调类
 */

#ifndef AIR_CONDITIONER_H
#define AIR_CONDITIONER_H

#include <iostream>

using namespace std;

// 空调抽象类
class AirConditioner
{
public:
    virtual ~AirConditioner() = default;
    virtual void get_style_of_air_conditioner() = 0;
};

// 空调具体类
class AirConditionerA: public AirConditioner
{
public:
    virtual ~AirConditionerA() override = default;
    virtual void get_style_of_air_conditioner()
    {
        cout << "offer air conditioner A" << endl;
        return;
    }
};

class AirConditionerB: public AirConditioner
{
public:
    virtual ~AirConditionerB() override = default;
    virtual void get_style_of_air_conditioner()
    {
        cout << "offer air conditioner B" << endl;
        return;
    }
};

#endif // AIR_CONDITIONER_H





