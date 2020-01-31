/*
 * @Author: SourDumplings
 * @Date: 2019-10-31 08:51:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 */

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        for (int i = 0; i < n; i++)
        {
            if (letters[i] > target)
            {
                return letters[i];
            }
        }
        return letters[0];
    }
};