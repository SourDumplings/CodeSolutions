/*
 @Date    : 2018-03-13 14:38:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/826
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    vector<int> v;
    int num;
    while (true)
    {
        cin >> num;
        if (num < 0) break;
        v.push_back(num);
    }
    int n = v.size();
    if (n < k)
        printf("NULL\n");
    else
        printf("%d\n", v[n-k]);
    return 0;
}

