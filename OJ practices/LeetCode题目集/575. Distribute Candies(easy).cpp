/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 20:17:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/distribute-candies/
 * 
 * 妹妹拿到的最大种类数肯定是总种类数或者是总糖果数的一半，谁小就是谁
 */

class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {
        unordered_set<int> s(candies.begin(), candies.end());
        return min(s.size(), candies.size() / 2);
    }
};