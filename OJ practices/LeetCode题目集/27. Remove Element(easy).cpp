/*
 @Date    : 2019-01-15 19:59:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/remove-element/
 */

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.empty())
        {
            return 0;
        }
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (*it == val)
            {
                it = nums.erase(it);
            }
            else
                ++it;
        }
        return nums.size();
    }
};

