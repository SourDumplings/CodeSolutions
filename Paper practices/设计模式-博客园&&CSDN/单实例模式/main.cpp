/*
 @Date    : 2018-04-25 13:58:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
皇帝一般来说，一个时期只存在一个，下面用大臣参拜皇帝的例子来说明单实例模式。
Emperor代表皇帝类，大臣在主函数中参拜皇帝。
 */

#include <iostream>
#include <memory>

using namespace std;

class Emperor
{
private:
    Emperor();
    static shared_ptr<Emperor> _instance; // 唯一的皇帝单实例
public:
    static shared_ptr<Emperor> get_instance(); // 工厂方法来获得实例
    static void emperor_say(); // 类中其他方法，尽量是static
    ~Emperor();
};

shared_ptr<Emperor> Emperor::_instance = nullptr;

Emperor::Emperor()
{
    cout << "Emperor constructor" << endl;
    return;
}

Emperor::~Emperor() {}

shared_ptr<Emperor> Emperor::get_instance()
{
    if (_instance == nullptr)
    {
        _instance = shared_ptr<Emperor>(new Emperor);
    }
    return _instance;
}

void Emperor::emperor_say()
{
    cout << "我就是皇帝某某某。。。" << endl;
    return;
}


// 大臣类
class Minister {};


int main(int argc, char const *argv[])
{
    for (unsigned day = 0; day < 3; ++day)
    {
        //当GetInstance()为static时，才能保证实例由类本身来创建，
        //否则一个非static成员函数必须与特定对象搭配才能调用
        shared_ptr<Emperor> emperor = Emperor::get_instance();
        emperor->emperor_say();
        // 三天见的皇帝是同一个人
    }
    return 0;
}

