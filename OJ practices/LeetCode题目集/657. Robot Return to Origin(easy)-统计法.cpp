/*
 * @Author: SourDumplings
 * @Date: 2019-10-12 13:39:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/robot-return-to-origin/
 */

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int step[4]; // U 0, D 1, L 2, R 3
        step[0] = step[1] = step[2] = step[3] = 0;
        for (auto &&c : moves)
        {
            switch (c)
            {
            case 'U':
                step[0]++;
                break;
            case 'D':
                step[1]++;
                break;
            case 'L':
                step[2]++;
                break;
            case 'R':
                step[3]++;
                break;

            default:
                break;
            }
        }
        return step[0] == step[1] && step[2] == step[3];
    }
};