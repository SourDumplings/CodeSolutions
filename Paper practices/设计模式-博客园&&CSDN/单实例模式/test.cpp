/*
 @Date    : 2018-04-25 15:14:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
转自：https://blog.csdn.net/lanchunhui/article/details/50878505
 */

#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
public:
    static shared_ptr<Singleton> instance()
    {
        if (_instance == 0)
            _instance = shared_ptr<Singleton>(new Singleton);
        return _instance;
    }

    ~Singleton()
    {
        std::cout << "Singleton::~Singleton()" << std::endl;
    }
private:
    Singleton(const Singleton&);
    Singleton()
    {
        std::cout << "Singleton::Singleton()" << std::endl;
    }
    Singleton& operator=(const Singleton&);
    static shared_ptr<Singleton> _instance;
};

shared_ptr<Singleton> Singleton::_instance = NULL;

int main(int, char**)
{
    shared_ptr<Singleton> s = Singleton::instance();
    shared_ptr<Singleton> s2 = Singleton::instance();

    return 0;
}
