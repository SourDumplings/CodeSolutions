/*
 * @Author: SourDumplings
 * @Date: 2020-10-14 19:29:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/single-number-ii/
 */

class Solution
{
    public int singleNumber(int[] nums)
    {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums)
        {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (Integer integer : map.keySet())
        {
            if (map.get(integer) == 1)
            {
                return integer;
            }
        }
        return -1;
    }
}