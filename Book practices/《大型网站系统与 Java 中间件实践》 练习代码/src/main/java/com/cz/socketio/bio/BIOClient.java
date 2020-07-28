package com.cz.socketio.bio;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/28 14:31
 */
public class BIOClient
{
    public static void main(String[] args) throws IOException, InterruptedException
    {
        //创建客户端套接字 & 连接服务器
        Socket socket = new Socket("127.0.0.1", 9999);
        //拿到输入流 -- server write to client, client read from server
        InputStream in = socket.getInputStream();
        //拿到输出流 -- client write to server
        OutputStream out = socket.getOutputStream();
        byte[] sendByte = "hello".getBytes();
        while (true)
        {
            //client write to server
            out.write(sendByte);
            byte[] buf = new byte[32];
            //read from server
            int len = in.read(buf, 0, sendByte.length);
            //如果len == 1，说明server已经断开连接
            if (len == -1)
            {
                throw new RuntimeException("连接已断开");
            }
            System.out.println("recv:" + new String(buf, 0, len));
            Thread.sleep(1000);
        }
    }

}
