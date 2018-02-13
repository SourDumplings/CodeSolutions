/*
 @Date    : 2018-01-07 15:10:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/4w4
 */

#include <iostream>

using namespace std;

class MyInt
{
    int nVal;
public:
    MyInt(int n) { nVal = n; }
    int ReturnVal() { return nVal; }
    MyInt& operator-(int n) { nVal -= n; return *this; }
};
int main ()  {
    MyInt objInt(10);
    objInt - 2 - 1 - 3;
    cout << objInt.ReturnVal();
    cout << ",";
    objInt - 2 - 1;
    cout << objInt.ReturnVal();
    return 0;
}
