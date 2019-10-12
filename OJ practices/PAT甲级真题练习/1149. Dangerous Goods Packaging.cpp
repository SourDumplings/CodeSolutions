/*
 @Date    : 2018-09-11 09:02:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176
 */

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int MAX = 100005;
set<int> inC[MAX];
int N, M;

int main()
{
    cin >> N >> M;
    for (int i = 0; i != N; ++i)
    {
        int id1, id2;
        cin >> id1 >> id2;
        inC[id1].insert(id2);
        inC[id2].insert(id1);
    }
    for (int i = 0; i != M; ++i)
    {
        int K;
        vector<int> v;
        cin >> K;
        bool flag = true;
        for (int j = 0; j != K; ++j)
        {
            int id;
            cin >> id;
            if (flag)
            {
                for (int vi : v)
                {
                    if (!inC[vi].empty() && inC[vi].find(id) != inC[vi].end())
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                v.push_back(id);
        }
        if (flag)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
