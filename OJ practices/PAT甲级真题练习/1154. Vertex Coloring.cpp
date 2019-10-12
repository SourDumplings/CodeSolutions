/*
 @Date    : 2019-01-04 10:30:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
vector<unordered_set<int>> G;
int N, M, K;
vector<int> colors;
unordered_set<int> colorsSet;

bool judge(int color, int s)
{
    for (int d : G[s])
        if (colors[d] == color)
            return false;
    return true;
}

int main()
{
    cin >> N >> M;
    G.resize(N);
    colors.resize(N);
    for (int i = 0; i != M; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    cin >> K;
    bool flag = true;
    for (int i = 0; i != K; ++i)
    {
        colorsSet.clear();
        flag = true;
        fill(colors.begin(), colors.end(), -1);
        for (int j = 0; j != N; ++j)
        {
            cin >> colors[j];
            if (flag)
            {
                colorsSet.insert(colors[j]);
                flag = judge(colors[j], j);
            }
        }

        if (!flag)
            cout << "No" << endl;
        else
            cout << colorsSet.size() << "-coloring" << endl;
    }
    return 0;
}


