/*
 @Date    : 2018-09-02 08:21:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>

using namespace std;

int N, K;
const int INF = 999999;
string s;

struct City
{
    int hap;
    vector<pair<string, int>> adjs;
};

map<string, City> cities;
map<string, int> costs;
map<string, bool> visited;

string find_min_cost()
{
    string ret = "";
    int minC = INF;
    for (auto &cP : costs)
    {
        if (!visited[cP.first] && cP.second < minC)
        {
            minC = cP.second;
            ret = cP.first;
        }
    }
    return ret;
}

void Dijkstra()
{
    for (auto &cP : cities)
    {
        costs[cP.first] = INF;
        visited[cP.first] = false;
    }
    costs[s] = 0;

    while (true)
    {
        const string &v = find_min_cost();
        if (v == "")
            break;
        visited[v] = true;
        const City &vC = cities[v];
        for (auto &adjP : vC.adjs)
        {
            if (!visited[adjP.first] && costs[v] + adjP.second < costs[adjP.first])
                costs[adjP.first] = costs[v] + adjP.second;
        }
    }
    return;
}

vector<string> thisPath, resPath;
int thisHap = 0, maxHap = 0;
int leastCNum = 0;

void dfs(const string &w)
{
    thisPath.push_back(w);
    thisHap += cities[w].hap;
    if (w == s)
    {
        if (thisHap > maxHap || (thisHap == maxHap && thisPath.size() < resPath.size()))
        {
            resPath = thisPath;
            maxHap = thisHap;
        }
        ++leastCNum;
    }
    else
    {
        for (auto &vP : cities[w].adjs)
        {
            const string &v = vP.first;
            if (costs[v] + vP.second == costs[w])
            {
                dfs(v);
            }
        }
    }
    thisPath.pop_back();
    thisHap -= cities[w].hap;
    return;
}

int main()
{
    cin >> N >> K >> s;
    for (int i = 0; i != N - 1; ++i)
    {
        string name;
        int h;
        cin >> name >> h;
        cities[name].hap = h;
    }
    for (int i = 0; i != K; ++i)
    {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        cities[c1].adjs.push_back(pair<string, int>(c2, cost));
        cities[c2].adjs.push_back(pair<string, int>(c1, cost));
    }
    Dijkstra();
    dfs("ROM");
    printf("%d %d %d %d\n", leastCNum, costs["ROM"], maxHap, maxHap / (resPath.size() - 1));
    int output = 0;
    for (auto it = resPath.rbegin(); it != resPath.rend(); ++it)
    {
        if (output++)
            printf("->");
        printf("%s", it->c_str());
    }
    putchar('\n');
    return 0;
}


