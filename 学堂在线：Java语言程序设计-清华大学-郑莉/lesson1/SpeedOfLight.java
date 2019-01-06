/**
 * @Date    : 2018-04-05 20:48:02
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * 计算光的传播距离
*/

import java.util.*;
import java.io.*;

public class SpeedOfLight
{
    public static void main(String[] args)
    {
        long speed = 299792458;
        long second;
        long distance;

        second = 24 * 60 * 60;
        distance = second * speed;
        System.out.println("光在一天中传播的距离是"+distance+"米");
    }
}


