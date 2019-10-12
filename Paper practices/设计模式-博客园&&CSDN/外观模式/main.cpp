/*
 @Date    : 2018-05-05 21:05:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
 假如你想吃一顿大餐，那么我想你要，首先去买菜，然后回到家后自己做菜，最后吃完饭以后要洗碗打扫。
     这么一来你需要3个类，Shopper， Cook， Dishwasher， 分别来完成买菜，做菜，洗碗等工作，
     显然这非常麻烦，能不能简化这个过程？当然可以！去餐馆吃。
     餐馆这时候显然就是外观模式了，他把复杂的过程封装到内部，用户不用关心细节。
实现代码：
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Shopper
{
public:
    void go_shopping()
    {
        cout << "买菜" << endl;
        return;
    }
};

class Cook
{
public:
    void cook()
    {
        cout << "做菜" << endl;
        return;
    }
};

class DishWasher
{
public:
    void wash_dishes()
    {
        cout << "洗碗" << endl;
        return;
    }
};

// 餐馆类，即外观类
class Resturant
{
public:
    void offer_a_meal()
    {
        m_shopper.go_shopping();
        m_cook.cook();
        cout << "上菜" << endl;
        m_dishWasher.wash_dishes();
        return;
    }
    static shared_ptr<Resturant> get_Resturant()
    {
        if (!m_resturant)
        {
            m_resturant = shared_ptr<Resturant>(new Resturant);
        }
        return m_resturant;
    }
private:
    Resturant()
    {
        cout << "一家餐馆盖起来了" << endl;
        return;
    }
    static shared_ptr<Resturant> m_resturant;
    Shopper m_shopper;
    Cook m_cook;
    DishWasher m_dishWasher;
};

shared_ptr<Resturant> Resturant::m_resturant = nullptr;

int main(int argc, char const *argv[])
{
    auto r = Resturant::get_Resturant();
    cout << "下馆子" << endl;
    r->offer_a_meal();
    return 0;
}

