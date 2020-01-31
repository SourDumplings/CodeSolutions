import java.util.Set;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-13 15:51:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-vowels-of-a-string/
 */

class Solution
{
    public String reverseVowels(String s)
    {
        int i = 0, j = s.length() - 1;
        char[] ss = s.toCharArray();
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        set.add('A');
        set.add('E');
        set.add('I');
        set.add('O');
        set.add('U');
        while (i < j)
        {
            while (i < j && !set.contains(ss[i]))
            {
                ++i;
            }
            while (i < j && !set.contains(ss[j]))
            {
                --j;
            }
            if (i < j)
            {
                char temp = ss[i];
                ss[i] = ss[j];
                ss[j] = temp;
                ++i;
                --j;
            }
        }
        return String.copyValueOf(ss);
    }
}