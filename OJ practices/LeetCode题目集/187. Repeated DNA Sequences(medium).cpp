/*
 * @Author: SourDumplings
 * @Date: 2020-12-18 12:16:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/repeated-dna-sequences/
 */

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int l = s.length();
        int L = 10;
        vector<string> res;
        unordered_map<string, int> hashMap;
        for (int i = 0; i < l - L + 1; ++i)
        {
            string subS = s.substr(i, L);
            if (hashMap.find(subS) == hashMap.end())
            {
                hashMap[subS] = 1;
            }
            else
            {
                if (hashMap[subS] == 1)
                {
                    res.push_back(subS);
                    ++hashMap[subS];
                }
            }
        }
        return res;
    }
};