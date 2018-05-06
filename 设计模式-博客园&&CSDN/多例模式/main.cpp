/*
 @Date    : 2018-04-26 14:15:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
思路：
指定实例的个数->用一个容器来存储实例->定义一个索引，用于查找指定的实例
当然，和单例模式一样，也需要将构造函数私有化
同时，实例个数，索引，容器等变量都是每个实例共有的，所以应声明为静态。

还是用之前单例模式中提到的皇帝的例子，假设有几个皇帝吧0.0
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

using namespace std;

class Emperor
{
private:
    Emperor(const string &name);
    // 定义最多能产生的实例数量
    static int maxNumOfEmperor;
    // 每个emperor都有name，用一个vector来容纳
    static vector<string> nameList;
    // 定义一个vector容纳所有实例
    static vector<shared_ptr<Emperor>> emperorList;
    // 当前emperor的序列号
    static int indexOfEmperor;
public:
    ~Emperor();
    // 产生所有实例
    static void produce_all_instances();
    // 获取实例
    static shared_ptr<Emperor> get_instance();
    // 实例的行为
    static void emperor_say();
};

// 所有静态成员的类外初始化
int Emperor::indexOfEmperor = 0;
int Emperor::maxNumOfEmperor = 3;
vector<string> Emperor::nameList;
vector<shared_ptr<Emperor>> Emperor::emperorList;

Emperor::Emperor(const string &name)
{
    cout << "c" << endl;
    nameList.push_back(name);
    return;
}

Emperor::~Emperor() { cout << "d" << endl; }

void Emperor::produce_all_instances()
{
    for (unsigned i = 0; i < maxNumOfEmperor; ++i)
    {
        string name = "Emperor" + to_string(i+1);
        emperorList.push_back(shared_ptr<Emperor>(new Emperor(name)));
        nameList.push_back(name);
    }
    return;
}

shared_ptr<Emperor> Emperor::get_instance()
{
    // 随机获得一个Emperor实例
    indexOfEmperor = rand() % maxNumOfEmperor;
    return emperorList[indexOfEmperor];
}

void Emperor::emperor_say()
{
    printf("I am %s\n", nameList[indexOfEmperor].c_str());
    return;
}

int main(int argc, char const *argv[])
{
    // 首先产生实例
    Emperor::produce_all_instances();
    // 假设有5位Ministers来参拜
    int ministerNum = 5;
    srand(time(0));
    for (unsigned i = 0; i < ministerNum; ++i)
    {
        shared_ptr<Emperor> emperor = Emperor::get_instance();
        printf("第%d个Minister参拜的是：\n", i+1);
        emperor->emperor_say();
    }
    return 0;
}

