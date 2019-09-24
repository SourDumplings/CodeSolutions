/*
 @Date    : 2017-12-19 14:14:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p243
 */

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vInt, unsigned index)
{
    unsigned sz = vInt.size();

    // 调试器
    #ifndef NDEBUG
    cout << "The size of vector is " << sz << endl;
    #endif

    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index+1);
    }
    else
    {
        return;
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    print(v, 0);
    return 0;
}
