/*
 * @Author: SourDumplings
 * @Date: 2019-10-12 13:45:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/robot-return-to-origin/
 */

class Solution
{
    public boolean judgeCircle(String moves)
    {
        int x = 0, y = 0;
        int l = moves.length();
        for (int i = 0; i < l; i++)
        {
            char c = moves.charAt(i);
            switch (c)
            {
            case 'U':
                ++y;
                break;
            case 'D':
                --y;
                break;
            case 'L':
                --x;
                break;
            case 'R':
                ++x;
                break;

            default:
                break;
            }
        }
        return x == 0 && y == 0;
    }
}