/*
 @Date    : 2018-03-13 12:04:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/723
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    unordered_map<string, string> data;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        char op;
        string a, pw;
        cin >> op >> a >> pw;
        if (op == 'L')
        {
            if (data.find(a) == data.end())
                printf("ERROR: Not Exist\n");
            else
            {
                if (pw == data[a])
                    printf("Login: OK\n");
                else
                    printf("ERROR: Wrong PW\n");
            }
        }
        else if (op == 'N')
        {
            if (data.find(a) != data.end())
                printf("ERROR: Exist\n");
            else
            {
                data[a] = pw;
                printf("New: OK\n");
            }
        }
    }
    return 0;
}

