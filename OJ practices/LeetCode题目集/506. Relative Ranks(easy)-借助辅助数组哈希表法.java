import java.util.Arrays;
import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-28 15:50:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/relative-ranks/
 */

class Solution
{
    public String[] findRelativeRanks(int[] nums)
    {
        int n = nums.length;
        Integer[] temp = new Integer[n];
        for (int i = 0; i < n; i++)
        {
            temp[i] = nums[i];
        }
        Arrays.sort(temp, (i1, i2) -> i2 - i1);
        Map<Integer, Integer> map = new Hashtable<>();
        for (int i = 0; i < n; i++)
        {
            map.put(temp[i], i);
        }
        String[] res = new String[n];
        for (int i = 0; i < n; i++)
        {
            int r = map.get(nums[i]);
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
        }
        return res;
    }
}