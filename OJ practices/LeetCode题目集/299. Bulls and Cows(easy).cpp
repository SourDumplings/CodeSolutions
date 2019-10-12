/*
 * @Author: SourDumplings
 * @Date: 2019-09-08 22:27:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/bulls-and-cows/
 */

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int l = secret.length();
        int bulls = 0, cows = 0;
        int s[11], g[11];
        fill(s, s + 11, 0);
        fill(g, g + 11, 0);
        for (int i = 0; i < l; i++)
        {
            if (secret[i] == guess[i])
            {
                ++bulls;
            }
            else
            {
                ++s[secret[i] - '0'];
                ++g[guess[i] - '0'];
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (g[i] > s[i])
            {
                cows += s[i];
            }
            else
            {
                cows += g[i];
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};