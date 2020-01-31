/*
 * @Author: SourDumplings
 * @Date: 2019-09-27 15:23:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/construct-the-rectangle/
 */

class Solution
{
    public int[] constructRectangle(int area)
    {
        int[] res = new int[2];
        int max = (int) Math.sqrt(area);
        for (int w = max; w >= 0; --w)
        {
            if (area % w == 0)
            {
                int l = area / w;
                res[0] = l;
                res[1] = w;
                break;
            }
        }
        return res;
    }
}