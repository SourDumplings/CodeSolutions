/*
 @Date    : 2018-01-12 21:29:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p683
 */

#include <iostream>
#include <string>

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
    // cout << compare("abc", "abcd") << endl;
    cout << compare<string>("abc", "abcd") << endl;
    return 0;
}
