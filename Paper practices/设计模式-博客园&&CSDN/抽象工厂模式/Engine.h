/*
 @Date    : 2018-04-26 20:07:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
引擎类
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

using namespace std;

// 引擎抽象类
class Engine
{
public:
    virtual ~Engine() = default;
    virtual void get_style_of_engine() = 0;
};

// 引擎具体类
class EngineA: public Engine
{
public:
    ~EngineA() override = default;
    void get_style_of_engine()
    {
        cout << "offer Engine A" << endl;
        return;
    }
};

class EngineB: public Engine
{
public:
    ~EngineB() override = default;
    void get_style_of_engine()
    {
        cout << "offer Engine B" << endl;
        return;
    }
};

#endif // ENGINE_H





