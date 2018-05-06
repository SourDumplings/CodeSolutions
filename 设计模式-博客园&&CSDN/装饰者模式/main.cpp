/*
 @Date    : 2018-05-03 19:13:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
假如你老婆喜欢化妆，她每天早上照镜子着镜子都化妆，化妆的时候要涂口红，画睫毛，抹香水。
老婆化妆的这个过程便是一个典型的装饰者模式，而口红，眼线笔，香水，显然就是装饰品。
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// 爱照镜子的女人
class Women
{
public:
    virtual void look_into_the_mirror() = 0;
};

// 需要装饰的类
class Wife : public Women
{
public:
    void look_into_the_mirror()
    {
        cout << "镜子中的老婆 " << endl;
        return;
    }
};

class Sister : public Women
{
public:
    void look_into_the_mirror()
    {
        cout << "镜子中的妹妹 " << endl;
        return;
    }
};

// 一个化妆的女人（装饰品的抽象基类）
class DecoratorWomen : public Women
{
public:
    DecoratorWomen(const shared_ptr<Women> &woman)
        : m_women(woman)
    {

    }

    void look_into_the_mirror()
    {
        m_women->look_into_the_mirror();
        make_up();
    }
    virtual void make_up() = 0; //化妆
protected:
    shared_ptr<Women> m_women;
};

// 化妆品
class Lipstick : public DecoratorWomen
{
public:
    Lipstick(const shared_ptr<Women> &woman): DecoratorWomen(woman) {};
    void make_up()
    {
        cout << "有火红的嘴唇！" << endl;
    }
};


class Mascara : public DecoratorWomen
{
public:
    Mascara(const shared_ptr<Women> &woman): DecoratorWomen(woman) {};
    void make_up()
    {
        cout << "有黑黑的睫毛！" << endl;
    }
};

class Perfume : public DecoratorWomen
{
public:
    Perfume(const shared_ptr<Women> &woman): DecoratorWomen(woman) {};
    void make_up()
    {
        cout << "有香奈儿的味道！" << endl;
    }
};

int main(int argc, char const *argv[])
{
    shared_ptr<Women> myWife(new Wife());
    shared_ptr<Lipstick> lips(new Lipstick(myWife));
    shared_ptr<Mascara> mas(new Mascara(lips));
    shared_ptr<Perfume> per(new Perfume(mas));
    myWife = per;
    myWife->look_into_the_mirror();

    cout << "..................." << endl;

    shared_ptr<Women> mySister(new Sister());
    shared_ptr<Lipstick> lips1(new Lipstick(mySister));
    shared_ptr<Perfume> per1(new Perfume(lips1));
    mySister = per1;
    mySister->look_into_the_mirror();
    return 0;
}

