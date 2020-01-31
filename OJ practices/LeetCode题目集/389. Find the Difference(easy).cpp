/*
 * @Author: SourDumplings
 * @Date: 2019-09-20 08:35:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-the-difference/
 */

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int hashTable[26];
        fill(hashTable, hashTable + 26, 0);
        for (auto &&c : s)
        {
            ++hashTable[c - 'a'];
        }
        for (auto &&c : t)
        {
            int i = c - 'a';
            if (hashTable[i] == 0)
            {
                return c;
            }
            else
            {
                --hashTable[i];
            }
        }
        return -1;
    }
};