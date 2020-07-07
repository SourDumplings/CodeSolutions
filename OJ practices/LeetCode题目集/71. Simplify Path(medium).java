/*
 * @Author: SourDumplings
 * @Date: 2020-07-07 19:45:24
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/simplify-path/
 */ 


class Solution
{
    public String simplifyPath(String path)
    {
        List<Character> list = new LinkedList<>();
        int l = path.length();
        boolean first = true;
        char lastC = '0';
        for (int i = 0; i < l; i++)
        {
            char thisC = path.charAt(i);
            if (first)
            {
                first = false;
                list.add(thisC);
            }
            else
            {
                if (thisC == '/')
                {
                    if (lastC != '/')
                    {
                        list.add(thisC);
                    }
                }
                else if (thisC == '.')
                {
                    char nextC = i < l - 1 ? path.charAt(i + 1) : '0';
                    char nextNextC = i < l - 2 ? path.charAt(i + 2) : '0';
                    if (nextC == '.' && lastC == '/')
                    {
                        if (nextNextC == '/' || i >= l - 2)
                        {
                            list.remove(list.size() - 1);
                            for (int j = list.size() - 1; j > -1; j--)
                            {
                                char endC = list.get(j);
                                list.remove(j);
                                if (endC == '/')
                                {
                                    break;
                                }
                            }
                            ++i;
                        }
                        else
                        {
                            for (; i < l && path.charAt(i) == '.'; i++)
                            {
                                list.add('.');
                            }
                            --i;
                        }
                    }
                    else if (nextC == '/' || i == l - 1)
                    {
                        thisC = '/';
                    }
                    else
                    {
                        list.add(thisC);
                    }
                }
                else
                {
                    list.add(thisC);
                }
            }
            lastC = thisC;
        }
        if (list.isEmpty() || list.get(0) != '/')
        {
            list.add(0, '/');
        }
        if (list.size() > 1 && lastC == '/')
        {
            list.remove(list.size() - 1);
        }
        StringBuilder sb = new StringBuilder();
        for (Character c : list)
        {
            sb.append(c);
        }
        return sb.toString();
    }
}