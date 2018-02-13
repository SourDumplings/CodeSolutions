/*
 @Date    : 2018-02-12 21:30:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
下列程序每次读入一个整数N，若N为0则退出，否则输出N和N的平方。
 */

#include <iostream>
using namespace std;
// 在此处补充你的代码

class CType
{
    friend ostream& operator<<(ostream &os, const CType &rhs);
private:
    int value;
public:
    void setvalue(int n) { value = n; return; }
    CType() = default;
    CType(const CType &c): value(c.value) {}
    int operator++(int) { int temp = value; value *= value; return temp; }
};

ostream& operator<<(ostream &os, const CType &rhs)
{ os << rhs.value; return os; }

int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}
