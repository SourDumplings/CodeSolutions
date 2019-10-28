package socket.server.threaded;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * 使用线程池优化了ThreadedEchoServer的线程管理。
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 16:11
 */
public class ThreadPoolEchoServer
{
    public static void main(String[] args)
    {
        ExecutorService pool = null;
        try (ServerSocket s = new ServerSocket(8189))
        {
            int i = 1;
            pool = Executors.newCachedThreadPool();

            while (true)
            {
                Socket incoming = s.accept();
                System.out.println("Spawning " + i);
                Runnable r = new ThreadedEchoHandler(incoming);
                pool.submit(r);
                ++i;
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        finally
        {
            assert pool != null;
            pool.shutdown();
        }
    }
}
