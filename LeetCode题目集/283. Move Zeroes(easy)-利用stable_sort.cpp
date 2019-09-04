/*
 * @Author: SourDumplings
 * @Date: 2019-09-04 21:47:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/move-zeroes/
 * 
 */

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        stable_sort(nums.begin(), nums.end(), [](const int &i1, const int &i2) {
            if (i1 != 0 && i2 == 0)
            {
                return true;
            }
            return false;
        });
    }
};