/**
 * @file 219. Contains Duplicate II(easy).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-05-02
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (m.find(num) != m.end()
                && i - m.at(num) <= k
            )
            {
                return true;
            }
            m[num] = i;
        }
        return false;
    }
};