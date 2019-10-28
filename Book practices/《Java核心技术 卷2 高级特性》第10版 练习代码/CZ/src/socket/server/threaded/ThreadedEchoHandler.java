package socket.server.threaded;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 * This class handles the client input for one server socket connection.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 15:52
 */
public class ThreadedEchoHandler implements Runnable
{
    private Socket incoming;

    /**
     * Constructs a handler.
     *
     * @param incomingSocket
     */
    public ThreadedEchoHandler(Socket incomingSocket)
    {
        incoming = incomingSocket;
    }

    @Override
    public void run()
    {
        try (InputStream inputStream = incoming.getInputStream();
            final OutputStream outputStream = incoming.getOutputStream())
        {
            Scanner in = new Scanner(inputStream);
            PrintWriter out = new PrintWriter(new OutputStreamWriter(outputStream, "UTF-8"), true);
            out.println("Hello! Enter BYE to exit.");

            // echo client input
            boolean done = false;
            while (!done && in.hasNextLine())
            {
                String line = in.nextLine();
                out.println("Echo: " + line);
                if (line.trim().equals("BYE"))
                {
                    done = true;
                }
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

    }
}
