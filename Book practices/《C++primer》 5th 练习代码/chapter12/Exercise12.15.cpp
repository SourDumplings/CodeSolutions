/*
 @Date    : 2017-12-30 16:50:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p469
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    cout << "打开连接" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "关闭连接" << endl;
}

// 未使用智能指针
void f(destination &d)
{
    cout << "直接管理connect" << endl;
    connection c = connect(&d);
    // 忘记调用disconnect关闭连接
    cout << endl;
    return;
}

// 使用智能指针
void f1(destination &d)
{
    cout << "用shared_ptr管理connect" << endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p);});
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    destination d;
    f(d);
    f1(d);
    return 0;
}
