/*
 @Date    : 2018-01-11 11:53:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
 */

#include <iostream>
#include <string>

using namespace std;

template <typename T, unsigned N> unsigned size(const T (&A)[N])
{
    return N;
}

int main(int argc, char const *argv[])
{
    int ai[5] = {1};
    cout << size(ai) << endl;
    string as[100] = {"11"};
    cout << size(as) << endl;
    return 0;
}
