package socket.server.threaded;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * This program implements a multithreaded server that listens to port 8189 and echos back all
 * client input.
 * 使用telnet localhost 8189即可建立连接
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 15:50
 */
public class ThreadedEchoServer
{
    public static void main(String[] args)
    {
        try (ServerSocket s = new ServerSocket(8189))
        {
            int i = 1;

            while (true)
            {
                Socket incoming = s.accept();
                System.out.println("Spawning " + i);
                Runnable r = new ThreadedEchoHandler(incoming);
                Thread t = new Thread(r);
                t.start();
                ++i;
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
