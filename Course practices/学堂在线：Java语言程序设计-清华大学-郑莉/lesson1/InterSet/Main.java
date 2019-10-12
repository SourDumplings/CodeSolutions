/**
 * @Date    : 2018-04-06 14:04:37
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * 交集
*/

import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int count = 0;

        int N1 = cin.nextInt();
        int[] A1 = new int[N1];
        for (int i = 0; i != N1; ++i)
        {
            A1[i] = cin.nextInt();
        }
        int N2 = cin.nextInt();
        int[] A2 = new int[N2];
        for (int i = 0; i != N2; ++i)
        {
            A2[i] = cin.nextInt();
        }

        cin.close();
        for (int i = 0; i != N1; ++i)
        {
            for (int j = 0; j != N2; ++j)
            {
                if (A2[j] == A1[i])
                {
                    ++count;
                }
            }
        }

        if (count != 0)
        {
            System.out.println(count);
        }
        else
            System.out.println("None");
    }
}


