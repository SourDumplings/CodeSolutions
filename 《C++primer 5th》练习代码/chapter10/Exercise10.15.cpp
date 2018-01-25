/*
 @Date    : 2017-12-26 21:48:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p392
 */

#include <iostream>

using namespace std;

void add(int a)
{
    auto sum = [a] (int b) {return a + b;};
    cout << sum(3) << endl;
    return;
}

int main(int argc, char const *argv[])
{
    add(1);
    add(2);
    return 0;
}
