package socket;

import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

/**
 * This program makes a socket connection to the atomic clock in Boulder, Colorado, and prints
 * the time that the server sends.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 10:42
 */
public class SocketTest
{
    public static void main(String[] args) throws IOException
    {
        try (Socket s = new Socket("time-a.nist.gov", 13);
            Scanner in = new Scanner(s.getInputStream(), "UTF-8"))
        {
            while (in.hasNextLine())
            {
                System.out.println(in.nextLine());
            }
        }
    }
}
