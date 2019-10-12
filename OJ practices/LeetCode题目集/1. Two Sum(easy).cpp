/*
 @Date    : 2018-01-05 13:18:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/two-sum/description/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for(int i = 0; i != nums.size(); ++i)
        {
            for(int j = i + 1; j != nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                    return *(new vector<int>{i, j});
            }
        }
    }
};
