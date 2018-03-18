/*
 @Date    : 2018-03-03 15:59:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1124
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);
    string data[M];
    map<string, bool> isWinner;
    vector<string> winners;
    for (int i = 0; i != M; ++i)
    {
        cin >> data[i];
        isWinner.insert(make_pair(data[i], false));
    }
    for (int i = S - 1; i < M;)
    {
        if (isWinner[data[i]]) ++i;
        else
        {
            isWinner[data[i]] = true;
            winners.push_back(data[i]);
            i += N;
        }
    }
    for (auto winner : winners)
        cout << winner << endl;
    if (winners.empty())
        printf("Keep going...\n");
    return 0;
}
