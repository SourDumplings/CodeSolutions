import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @Autor: SourDumplings
 * @Date: 2019-11-28 21:49:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/subdomain-visit-count/
 */

class Solution
{
    public List<String> subdomainVisits(String[] cpdomains)
    {
        Map<String, Integer> map = new HashMap<>();
        for (String cpdomain : cpdomains)
        {
            String[] temp = cpdomain.split("\\s+");
            int visitNum = Integer.parseInt(temp[0]);
            String[] domainElements = temp[1].split("\\.");
            int l = domainElements.length;
            StringBuilder sb = new StringBuilder();
            for (int i = l - 1; i >= 0; i--)
            {
                if (i < l - 1)
                {
                    sb.insert(0, ".");
                }
                sb.insert(0, domainElements[i]);
                String domain = sb.toString();
                map.merge(domain, visitNum, Integer::sum);
            }
        }
        List<String> res = new ArrayList<>();
        for (String domain : map.keySet())
        {
            Integer num = map.get(domain);
            StringBuilder sb = new StringBuilder(num.toString());
            sb.append(" ").append(domain);
            res.add(sb.toString());
        }
        return res;
    }
}