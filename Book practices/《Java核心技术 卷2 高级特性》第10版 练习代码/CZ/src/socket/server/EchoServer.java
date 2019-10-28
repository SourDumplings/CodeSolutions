package socket.server;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

/**
 * This program implements a simple server that listens to port 8189 and echoes back all client
 * input.
 * 使用telnet: telnet localhost 8189
 * 即可连接这个服务器Socket
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 15:26
 */
public class EchoServer
{
    public static void main(String[] args) throws IOException
    {
        // establish server socket
        try (ServerSocket s = new ServerSocket(8189))
        {
            // wait for client connection
            try (Socket incoming = s.accept())
            {
                InputStream inputStream = incoming.getInputStream();
                OutputStream outputStream = incoming.getOutputStream();

                try (Scanner in = new Scanner(inputStream, "UTF-8"))
                {
                    PrintWriter out = new PrintWriter(
                        new OutputStreamWriter(outputStream, "UTF-8"), true);
                    out.println("Hello! Enter BYE to exit.");

                    // echo client input
                    boolean done = false;
                    while (!done && in.hasNextLine())
                    {
                        final String line = in.nextLine();
                        out.println("Echo: " + line);
                        if (line.trim().equals("BYE"))
                        {
                            done = true;
                        }
                    }
                }
            }
        }
    }
}
