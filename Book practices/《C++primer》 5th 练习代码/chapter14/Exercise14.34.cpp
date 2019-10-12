/*
 @Date    : 2018-01-06 14:06:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p572
 */

#include <iostream>
#include <string>

using namespace std;

class If
{
private:
    bool judge = false;
public:
    void operator()(bool first, string &second, string &third)
    { cout << (first == judge ? second : third) << endl; }
    void operator()(bool first, const string &second, const string &third)
    { cout << (first == judge ? second : third) << endl; }
};

int main(int argc, char const *argv[])
{
    If i;
    i(1 > 2, "4", "3");
    i("a" < string("b"), "abc", "0");
    return 0;
}
