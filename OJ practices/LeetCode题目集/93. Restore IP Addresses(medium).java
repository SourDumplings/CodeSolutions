/*
 * @Author: SourDumplings
 * @Date: 2020-08-22 10:23:17
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/restore-ip-addresses/
 */

class Solution
{
    private List<String> res = new ArrayList<>();
    private List<Integer> thisIP = new ArrayList<>();

    public List<String> restoreIpAddresses(String s)
    {
        solve(s, 0);
        return res;
    }

    private void solve(String s, int start)
    {
        if (thisIP.size() == 4)
        {
            if (start == s.length())
            {
                StringBuilder sb = new StringBuilder();
                sb.append(thisIP.get(0)).append(".").append(thisIP.get(1)).append(".")
                    .append(thisIP.get(2)).append(".").append(thisIP.get(3));
                res.add(sb.toString());
            }
        }
        else if (start < s.length())
        {
            String s1 = s.substring(start, start + 1);
            thisIP.add(Integer.parseInt(s1));
            solve(s, start + 1);
            thisIP.remove(thisIP.size() - 1);

            if (start < s.length() - 1)
            {
                String s2 = s.substring(start, start + 2);
                if (s2.charAt(0) != '0')
                {
                    int num = Integer.parseInt(s2);
                    thisIP.add(num);
                    solve(s, start + 2);
                    thisIP.remove(thisIP.size() - 1);
                }
            }

            if (start < s.length() - 2)
            {
                String s3 = s.substring(start, start + 3);
                if (s3.charAt(0) != '0')
                {
                    int num = Integer.parseInt(s3);
                    if (num <= 255)
                    {
                        thisIP.add(num);
                        solve(s, start + 3);
                        thisIP.remove(thisIP.size() - 1);
                    }
                }
            }
        }
    }
}