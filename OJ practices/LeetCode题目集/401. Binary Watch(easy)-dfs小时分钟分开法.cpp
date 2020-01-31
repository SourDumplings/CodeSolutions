/*
 * @Author: SourDumplings
 * @Date: 2019-09-22 07:06:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-watch/
 * 
 */

class Solution
{
private:
    int power[6] = {1, 2, 4, 8, 16, 32};

public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> res;
        if (num == 0)
        {
            res.push_back("0:00");
        }
        else
        {
            for (int h = 0; h <= num; h++)
            {
                if (h < 4 && num - h < 6 && num - h >= 0) // 不可能亮6个或以上分钟灯，也不能亮4个或以上的小时灯
                {
                    combine(res, h, num - h);
                }
            }
        }
        return res;
    }

    void combine(vector<string> &res, int h, int m)
    {
        vector<int> hours, minutes;
        if (h > 0)
        {
            for (int i = 0; i < 4; i++)
            {
                dfs(hours, h - 1, i, 4, 0);
            }
        }
        else
        {
            hours.push_back(0);
        }

        if (m > 0)
        {
            for (int i = 0; i < 6; i++)
            {
                dfs(minutes, m - 1, i, 6, 0);
            }
        }
        else
        {
            minutes.push_back(0);
        }

        int hNum = hours.size();
        int mNum = minutes.size();
        for (int i = 0; i < hNum; i++)
        {
            for (int j = 0; j < mNum; j++)
            {
                process(res, hours[i], minutes[j]);
            }
        }
    }

    void dfs(vector<int> &num, int n, int b, int e, int value)
    {
        value += power[b];
        if (n == 0)
        {
            num.push_back(value);
        }
        else
        {
            for (int i = b + 1; i < e; i++)
            {
                dfs(num, n - 1, i, e, value);
            }
        }
        value -= power[n];
    }

    void process(vector<string> &res, int h, int m)
    {
        if (h >= 12 || m >= 60)
        {
            return;
        }

        char minutes[4];
        sprintf(minutes, ":%02d", m);
        res.push_back(to_string(h) + minutes);
    }
};