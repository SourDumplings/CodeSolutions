/*
 * @Author: SourDumplings
 * @Date: 2020-12-10 17:22:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/compare-version-numbers/
 */

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int l1 = version1.length();
        int l2 = version2.length();
        int i1 = 0, i2 = 0;
        while (i1 < l1 && i2 < l2)
        {
            int num1, num2;
            int b1 = i1, b2 = i2;
            while (i1 < l1 && version1[i1] != '.')
            {
                ++i1;
            }
            while (i2 < l2 && version2[i2] != '.')
            {
                ++i2;
            }
            num1 = stoi(version1.substr(b1, i1 - b1));
            num2 = stoi(version2.substr(b2, i2 - b2));
            if (num1 < num2)
            {
                return -1;
            }
            else if (num2 < num1)
            {
                return 1;
            }
            if (i1 == l1 && i2 < l2)
            {
                while (i2 < l2)
                {
                    ++i2;
                    b2 = i2;
                    while (i2 < l2 && version2[i2] != '.')
                    {
                        ++i2;
                    }
                    num2 = stoi(version2.substr(b2, i2 - b2));
                    if (num2 > 0)
                    {
                        return -1;
                    }
                }
            }
            if (i2 == l2 && i1 < l1)
            {
                while (i1 < l1)
                {
                    ++i1;
                    b1 = i1;
                    while (i1 < l1 && version1[i1] != '.')
                    {
                        ++i1;
                    }
                    num1 = stoi(version1.substr(b1, i1 - b1));
                    if (num1 > 0)
                    {
                        return 1;
                    }
                }
            }
            ++i1;
            ++i2;
        }
        return 0;
    }
};