/*
 @Date    : 2018-01-02 19:08:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p510
我觉得不需要定义拷贝赋值操作符函数
 */

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    static int id_seq;
    Employee() { id = id_seq++; }
    Employee(const string &n) { name = n; id = id_seq++; }
    Employee(const Employee &e) { name = e.name; id = id_seq++; }
    string get_name() { return name; }
    int get_id() { return id; }
private:
    string name;
    int id;
};

void f(Employee &e)
{
    cout << e.get_name() << ":" << e.get_id() << endl;
    return;
}

int Employee::id_seq = 0;

int main(int argc, char const *argv[])
{
    Employee a("zhao"), b = a, c;
    c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
