import java.util.HashSet;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 20:53:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/distribute-candies/
 */

class Solution
{
    public int distributeCandies(int[] candies)
    {
        HashSet<Integer> set = new HashSet<Integer>();
        for (int i : candies)
        {
            set.add(i);
        }
        return Math.min(set.size(), candies.length / 2);
    }
}