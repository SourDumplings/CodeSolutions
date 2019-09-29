import java.util.SortedMap;
import java.util.TreeMap;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-28 16:16:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/relative-ranks/
 */

class Solution
{
    public String[] findRelativeRanks(int[] nums)
    {
        int n = nums.length;
        String[] res = new String[n];
        SortedMap<Integer, Integer> sMap = new TreeMap<>((i1, i2) -> i2 - i1);
        for (int i = 0; i < n; i++)
        {
            sMap.put(nums[i], i);
        }
        int r = 0;
        for (int i : sMap.values())
        {
            switch (r)
            {
            case 0:
                res[i] = "Gold Medal";
                break;
            case 1:
                res[i] = "Silver Medal";
                break;
            case 2:
                res[i] = "Bronze Medal";
                break;
            default:
                res[i] = String.valueOf(r + 1);
                break;
            }
            ++r;
        }
        return res;
    }
}