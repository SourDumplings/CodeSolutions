/*
 @Date    : 2018-01-11 11:33:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

template <typename T, unsigned N> void print(const T (&A)[N])
{
    printf("the size of the array passed is: %d\n", N);
    for (int i = 0; i != N; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int ai[10] = {0, 1, 2, 3};
    string as[5] = {"123", "dad", "asd33"};
    char ac[8] = {'s', '1', 's', '5', '8', 'e', 'r'};
    print(ai);
    print(as);
    print(ac);
    print("Hello");
    return 0;
}
