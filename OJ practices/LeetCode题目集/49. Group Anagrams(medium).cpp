/**
 * @file 49. Group Anagrams(medium).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 核心思想是用字符个数组成字符串，代表原字符串的哈希值
 * https://leetcode.cn/problems/group-anagrams/solutions/520469/zi-mu-yi-wei-ci-fen-zu-by-leetcode-solut-gyoc/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int>> idxMap;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            string hashStr = getHashStr(strs[i]);
            idxMap[std::move(hashStr)].emplace_back(i);
        }
        vector<vector<string>> res;
        for (const auto &p : idxMap)
        {
            vector<string> group;
            for (int i : p.second)
            {
                group.emplace_back(std::move(strs[i]));
            }
            res.emplace_back(std::move(group));
        }
        return res;
    }

private:
    string getHashStr(const string &s)
    {
        int count[26];
        memset(count, 0, sizeof(count));
        for (char c : s)
        {
            ++count[c - 'a'];
        }
        string res;
        for (int i = 0; i < 26; ++i)
        {
            res += static_cast<char>(count[i]);
        }
        return res;
    }
};