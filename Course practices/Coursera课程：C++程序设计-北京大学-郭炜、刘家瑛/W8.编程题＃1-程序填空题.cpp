/*
 @Date    : 2018-02-04 16:24:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/9w5/
 */

#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int main() {
    int a[] = {8,7,8,9,6,2,1};

// 在此处补充你的代码
    set<int> v(a, a+7);

    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o);
    return 0;
}
