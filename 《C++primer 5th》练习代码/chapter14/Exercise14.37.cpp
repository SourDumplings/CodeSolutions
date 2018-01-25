/*
 @Date    : 2018-01-06 14:27:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p572
 */

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class Equal
{
private:
    int val;
public:
    Equal(int v) : val(v) {}
    bool operator() (int v) { return val == v; }
};

int main(int argc, char const *argv[])
{
    Equal e(1);
    array<int, 10> a{1, 1, 2, 3, 6, 1, 2, 5, 6, 10};
    replace_if(a.begin(), a.end(), e, 0);
    for_each(a.begin(), a.end(), [] (int i) { cout << i << " "; });
    return 0;
}
