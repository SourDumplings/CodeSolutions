package inetAddress;

import java.io.IOException;
import java.net.InetAddress;
import java.util.Scanner;

/**
 * This program demonstrates the InetAddress class.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 11:06
 */
public class InetAddressTest
{
    public static void main(String[] args) throws IOException
    {
        System.out.println("Please input a host name:");
        try (Scanner in = new Scanner(System.in))
        {
            String host = in.nextLine();
            if (host.isEmpty())
            {
                InetAddress localHostAddress = InetAddress.getLocalHost();
                System.out.println(localHostAddress);
            }
            else
            {
                InetAddress[] addresses = InetAddress.getAllByName(host);
                for (InetAddress address : addresses)
                {
                    System.out.println(address);
                }
            }

        }
    }
}
