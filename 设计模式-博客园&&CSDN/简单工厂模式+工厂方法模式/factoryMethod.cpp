/*
 @Date    : 2018-04-26 16:33:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
工厂方法模式使用继承自抽象工厂角色的多个子类来代替简单工厂模式中的“上帝类”。正如上面所说，这样便分担了对象承受的压力；而且这样使得结构变得灵活 起来——当有新的产品产生时，只要按照抽象产品角色、抽象工厂角色提供的合同来生成，那么就可以被客户使用，而不必去修改任何已有的代码。可以看出工厂角色的结构也是符合开闭原则的！
 */

#include <iostream>
#include <cstdio>
#include <memory>

using namespace std;

// 抽象产品角色
class BMW
{
public:
    virtual ~BMW() = default;
    virtual void get_style() = 0;
};

// 具体产品角色
class BMW320: public BMW
{
public:
    void get_style()
    {
        cout << "produce BMW320" << endl;
        return;
    }
};

class BMW523: public BMW
{
public:
    void get_style()
    {
        cout << "produce BMW523" << endl;
        return;
    }
};

// 抽象工厂角色
class Factory
{
public:
    virtual ~Factory() = default;
    virtual shared_ptr<BMW> create_BMW() = 0;
};

// 具体工厂角色
class FactoryBMW320: public Factory
{
public:
    shared_ptr<BMW> create_BMW() override
    {
        return shared_ptr<BMW>(new BMW320);
    }
};

class FactoryBMW523: public Factory
{
public:
    shared_ptr<BMW> create_BMW() override
    {
        return shared_ptr<BMW>(new BMW523);
    }
};

int main(int argc, char const *argv[])
{
    shared_ptr<Factory> factorBMW320(new FactoryBMW320);
    shared_ptr<BMW> bmw320 = factorBMW320->create_BMW();
    bmw320->get_style();

    shared_ptr<Factory> factorBMW523(new FactoryBMW523);
    shared_ptr<BMW> bmw523 = factorBMW523->create_BMW();
    bmw320->get_style();
    return 0;
}

