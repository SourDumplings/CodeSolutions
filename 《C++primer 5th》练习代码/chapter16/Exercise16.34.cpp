/*
 @Date    : 2018-01-12 20:30:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p681
 */

#include <iostream>

using namespace std;

template <typename T>
int compare(const T &a, const T &b)
{
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    cout << compare("bye", "dad") << endl;
    // cout << compare("hi", "world") << endl;
    return 0;
}
