/*
 * @Author: SourDumplings
 * @Date: 2021-03-19 11:41:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/minimum-height-trees/
 * 
 * 用暴力法会超时
 * 使用拓扑排序从外到内进行BFS
 * 最内侧的即为结果
 */

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> res;
        if (n == 1)
        {
            res.push_back(0);
        }
        else
        {
            int minHeight = INT32_MAX;
            int degree[n];
            set<int> conn[n];
            bool checked[n];
            for (int i = 0; i < n; ++i)
            {
                degree[i] = 0;
                checked[i] = false;
            }
            for (vector<int> &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                conn[u].insert(v);
                conn[v].insert(u);
                ++degree[u];
                ++degree[v];
            }
            queue<int> q;
            for (int node = 0; node < n; ++node)
            {
                if (degree[node] == 1)
                {
                    q.push(node);
                    checked[node] = true;
                }
            }
            while (!q.empty())
            {
                res.clear();
                while (!q.empty())
                {
                    res.push_back(q.front());
                    q.pop();
                }
                for (int c : res)
                {
                    for (int f : conn[c])
                    {
                        if (!checked[f] && --degree[f] == 1)
                        {
                            q.push(f);
                            checked[f] = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};