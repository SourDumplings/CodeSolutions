/*
 @Date    : 2017-12-31 17:11:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/3w7
 */

#include <iostream>
using namespace std;
class A {
public:
    int val;
    A() : val(0) {}
    int& GetObj() { return val;};
};

main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}
