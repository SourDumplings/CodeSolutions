/*
 @Date    : 2017-12-31 17:17:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/3w8/
 */

#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
    Sample(Sample& a): v(10) { }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}
