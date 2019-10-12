/*
 @Date    : 2018-02-13 13:04:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
对人群按照输入的信息进行排序和分类。
 */

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class A
{
public:
    int age;
    char c;
    A(int k, char cl = 'A'): age(k), c(cl) {}
};

class B: public A
{
public:
    B(int k): A(k, 'B') {}
};

class Comp
{
public:
    bool operator()(A* const &pA1, A* const &pA2)
    {
        return pA1->age < pA2->age;
    }
};

void Print(A* const &pA)
{ cout << pA->c << ' ' << pA->age << endl; return; }

int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)  {
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}
