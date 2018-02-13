/*
 @Date    : 2018-02-12 21:53:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
输入一个正整数构成的数组a[0], a[1], a[2], ... , a[n-1], 计算它们的二进制低3位之和。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码

class CMy_add
{
public:
    int &sum;
    CMy_add(int &base_): sum(base_) {}
    void operator()(const int &i)
    {
        int temp = i & 7;
        sum += temp;
        return;
    }
};

ostream& operator<<(ostream &os, const CMy_add &c)
{
    os << c.sum;
    return os;
}

int main(int argc, char* argv[]) {
        int v, my_sum=0;
        vector<int> vec;
        cin>>v;
        while ( v ) {
                vec.push_back(v);
                cin>>v;
        }
        for_each(vec.begin(), vec.end(), CMy_add(my_sum));
        cout<<my_sum<<endl;
        return 0;
}
