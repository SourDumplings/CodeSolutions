/*
 @Date    : 2018-02-12 22:56:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
请按照要求对输入的字符串进行排序。
 */

#include <iostream>
#include <string>
#include <list>
using namespace std;

class A{
private:
        string name;
public:
        A(string n) :name(n){}
        friend bool operator < (const class A& a1, const class A &a2);
        friend bool operator == (const class A &a1, const class A &a2){
                if (a1.name.size() == a2.name.size())
                        return true;
                else
                        return false;
        }
        friend ostream & operator << (ostream &o, const A &a){
                o << a.name;
                return o;
        }
        string get_name() const{
                return name;
        }
        int get_size() const{
                return name.size();
        }
};
// 在此处补充你的代码
bool operator < (const class A& a1, const class A &a2)
{ return a1.get_size() < a2.get_size(); }

class Print
{
public:
    void operator()(const A &a) { cout << a.get_name(); }
};

void Show(list<A>::iterator begin, list<A>::iterator end, Print p)
{
    int output = 0;
    for (list<A>::iterator it = begin; it != end; ++it)
    {
        if (output++)
            cout << " ";
        p(*it);
    }
    return;
}

template <typename T>
class MyLarge
{
public:
    bool operator()(const T &t1, const T &t2) { return t1.get_name() < t2.get_name(); }
};

int main(int argc, char* argv[])
{
        list<A> lst;
        int ncase, n, i = 1;
        string s;
        cin >> ncase;
        while (ncase--){
                cout << "Case: "<<i++ << endl;
                cin >> n;
                for (int i = 0; i < n; i++){
                         cin >> s;
                         lst.push_back(A(s));
                }
                lst.sort();
                Show(lst.begin(), lst.end(), Print());

                cout << endl;
                lst.sort(MyLarge<A>());
                Show(lst.begin(), lst.end(), Print());
                cout << endl;
                lst.clear();
        }
        return 0;
}
