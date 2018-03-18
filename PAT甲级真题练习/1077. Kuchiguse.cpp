/*
 @Date    : 2018-02-14 18:03:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1077
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d\n", &N);
    string first, second, ku;
    getline(cin, first);
    getline(cin, second);
    int l1 = first.length(), l2 = second.length();
    int i, j;
    for (i = l1 - 1, j = l2 - 1; i >= 0 && j >= 0 && first[i] == second[j]; --i, --j);
    ku = std::move(first.substr(i+1));
    N -= 2;
    while (N--)
    {
        string next;
        getline(cin, next);
        int l = next.length(), k = ku.length();
        for (i = l - 1, j = k - 1; i >= 0 && j >= 0 && next[i] == ku[j]; --i, --j);
        if (j >= 0)
            ku.erase(ku.begin(), ku.begin() + j + 1);
    }
    if (ku.length())
        cout << ku << endl;
    else
        cout << "nai" << endl;
    return 0;
}
