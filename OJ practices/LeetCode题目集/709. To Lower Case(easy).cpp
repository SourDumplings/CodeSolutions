/*
 * @Autor: SourDumplings
 * @Date: 2019-10-27 08:30:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/to-lower-case/
 */

class Solution
{
public:
    string toLowerCase(string str)
    {
        int diff = 'A' - 'a';
        for (auto &c : str)
        {
            if ('A' <= c && c <= 'Z')
            {
                c -= diff;
            }
        }
        return std::move(str);
    }
};