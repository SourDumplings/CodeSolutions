/*
 @Date    : 2017-12-21 18:44:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p300
验证了string不是字面量类型，所以Data也不是字面量类型
 */

#include <iostream>
#include <string>

using namespace std;

struct Data
{
    int i;
    // string s;
};

int main(int argc, char const *argv[])
{
    // constexpr Data d{1, "abc"};
    constexpr Data d{1};
    return 0;
}
