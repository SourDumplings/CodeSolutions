
/**
 * @Date    : 2018-04-05 18:08:51
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * 简单的字符串排序
*/

import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        List<String> lists = new ArrayList<String>();
        for (int i = 0; i <= t; i++)
        {
            lists.add(cin.nextLine());
        }
        Collections.sort(lists);
        for (String li : lists)
        {
            System.out.println(li);
        }
    }
}
