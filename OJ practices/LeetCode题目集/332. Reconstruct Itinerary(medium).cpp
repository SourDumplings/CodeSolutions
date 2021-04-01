/*
 * @Author: SourDumplings
 * @Date: 2021-04-01 17:48:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/reconstruct-itinerary/
 */

class Solution
{
private:
    unordered_map<string, vector<int>> tMap;
    vector<string> res;
    vector<bool> used;
    int usedTicketNum = 0;
    int n;
    const int BIG = INT32_MAX / 2;

    void dfs(string airport, vector<vector<string>> &tickets)
    {
        if (usedTicketNum == n)
        {
            return;
        }
        vector<int> &nextTicketIndexes = tMap[airport];
        for (int &nextTicketIndex : nextTicketIndexes)
        {
            if (!used[nextTicketIndex])
            {
                string &nextAirport = tickets[nextTicketIndex][1];
                res.push_back(nextAirport);
                used[nextTicketIndex] = true;
                ++usedTicketNum;
                dfs(nextAirport, tickets);
                if (usedTicketNum == n)
                {
                    return;
                }
                --usedTicketNum;
                used[nextTicketIndex] = false;
                res.pop_back();
            }
        }
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        n = tickets.size();
        used.resize(n);
        for (int i = 0; i < n; ++i)
        {
            tMap[tickets[i][0]].push_back(i);
            used[i] = false;
        }
        for (auto &p : tMap)
        {
            sort(p.second.begin(), p.second.end(), [&tickets](int i1, int i2)
            {
                return tickets[i1] < tickets[i2];
            });
        }
        res.push_back("JFK");
        dfs("JFK", tickets);
        return res;
    }
};