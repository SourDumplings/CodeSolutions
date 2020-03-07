import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2020-03-07 21:49:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/group-anagrams/
 */

class Solution
{
    public List<List<String>> groupAnagrams(String[] strs)
    {
        Map<String, Integer> map = new HashMap<>();
        List<List<String>> res = new ArrayList<>();
        for (String str : strs)
        {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sortedStr = String.valueOf(chars);
            if (map.containsKey(sortedStr))
            {
                res.get(map.get(sortedStr)).add(str);
            }
            else
            {
                List<String> list = new ArrayList<>();
                list.add(str);
                res.add(list);
                map.put(sortedStr, res.size() - 1);
            }
        }
        return res;
    }
}