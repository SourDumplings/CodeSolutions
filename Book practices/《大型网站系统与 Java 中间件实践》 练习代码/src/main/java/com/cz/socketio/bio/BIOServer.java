package com.cz.socketio.bio;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/28 14:30
 */
public class BIOServer
{

    public static void main(String[] args) throws IOException
    {
        //创建服务端套接字 & 绑定host:port & 监听client
        ServerSocket serverSocket = new ServerSocket(9999);
        //等待客户端连接到来
        Socket socket = serverSocket.accept();
        //拿到输入流 -- client write to server
        InputStream in = socket.getInputStream();
        //拿到输出流 -- server write to client
        OutputStream out = socket.getOutputStream();
        while (true)
        {
            //将数据读到buf中
            byte[] buf = new byte[32];
            //server read from client
            int len = in.read(buf);
            //如果len == 1，说明client已经断开连接
            if (len == -1)
            {
                throw new RuntimeException("连接已断开");
            }

            System.out.println("recv:" + new String(buf, 0, len));

            //将读出来的数据写回给client
            //如果不使用偏移量，可能会将buf中的无效数据也写回给client
            out.write(buf, 0, len);
        }
    }
}

