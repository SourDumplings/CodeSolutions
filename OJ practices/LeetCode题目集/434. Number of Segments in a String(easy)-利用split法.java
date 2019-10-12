/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 11:49:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-segments-in-a-string/
 */

/*
* @Autor: SourDumplings
* @Date: 2019-09-25 11:46:56
* @Link: https://github.com/SourDumplings/
* @Email: changzheng300@foxmail.com
* @Description: https://leetcode.com/problems/number-of-segments-in-a-string/
*/

class Solution
{
    public int countSegments(String s)
    {
        s = s.trim();
        if (s.length() == 0)
        {
            return 0;
        }
        String[] res = s.split("\\s+");
        return res.length;
    }
}