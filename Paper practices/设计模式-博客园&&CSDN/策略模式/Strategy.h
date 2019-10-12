/*
 @Date    : 2018-04-24 18:38:22
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
策略抽象类
 */

#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy
{
public:
    Strategy() = default;
    virtual ~Strategy() {};

    // 纯虚函数，每个继承自它的具体策略类都要实现
    // 自己的策略方法
    virtual void operate() = 0;
};

#endif // STRATEGY_H


