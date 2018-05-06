/*
 @Date    : 2018-04-26 16:03:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
简单工厂模式又称为静态工厂方法模式。重命名上就可以看出这个模式一定很简单。
它存在的目的很简单：定义一个用于创建对象的接口
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// 抽象产品角色
class BMW
{
public:
    virtual ~BMW() {}
};

// 具体产品角色
class BMW320: public BMW
{
public:
    BMW320()
    { cout << "produce BMW320" << endl; }
    ~BMW320() override {}
};

class BMW523: public BMW
{
public:
    BMW523()
    { cout << "produce BMW523" << endl; }
    ~BMW523() override {}
};

// 工厂类角色
class Factory
{
public:
    shared_ptr<BMW> create_BMW(int type)
    {
        switch (type)
        {
            case 320: return shared_ptr<BMW320>(new BMW320);
            case 523: return shared_ptr<BMW523>(new BMW523);
            default: return nullptr;
        }
    }
};

int main(int argc, char const *argv[])
{
    shared_ptr<Factory> factory(new Factory);
    shared_ptr<BMW> bmw320= factory->create_BMW(320);
    shared_ptr<BMW> bmw523= factory->create_BMW(523);
    return 0;
}

