package com.cz.socketio.nio;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/28 14:53
 */
public class NIOClient
{
    public static void main(String[] args) throws IOException, InterruptedException
    {
        //创建客户端socket通道 & 连接host:port
        SocketChannel socketChannel = SocketChannel.open();
        //设置为非阻塞模式
        socketChannel.configureBlocking(false);
        //非阻塞的形式连接服务器，如果直接使用open带参数的，连接的时候是阻塞连接
        socketChannel.connect(new InetSocketAddress("127.0.0.1", 9999));
        //新创建一个selector
        Selector selector = Selector.open();
        //将该通道注册到该selector上，并且注明感兴趣的事件
        socketChannel.register(selector, SelectionKey.OP_CONNECT | SelectionKey.OP_READ);
        while (true)
        {
            selector.select();
            Set<SelectionKey> selectionKeys = selector.selectedKeys();
            Iterator<SelectionKey> iterator = selectionKeys.iterator();
            while (iterator.hasNext())
            {
                SelectionKey selectionKey = iterator.next();
                iterator.remove();
                //连接事件
                if (selectionKey.isConnectable())
                {
                    //看源码的注释可以知道，如果不使用带参数的open，那么需要手动调用这个方法完成连接
                    //如果是阻塞模式，该方法会阻塞到连接成功，非阻塞模式下，会立刻返回，已连接true，未连接false
                    if (socketChannel.finishConnect())
                    {
                        //需要取消连接事件，否则会一直触发该事件,注册写事件
                        selectionKey.interestOps(
                            selectionKey.interestOps() & ~SelectionKey.OP_CONNECT
                                | SelectionKey.OP_WRITE);
                    }
                }
                else if (selectionKey.isReadable())
                {
                    ByteBuffer buffer = ByteBuffer.allocate(32);
                    int len = socketChannel.read(buffer);
                    if (len == -1)
                    {
                        throw new RuntimeException("连接已断开");
                    }
                    byte[] buf = new byte[len];
                    buffer.flip();
                    buffer.get(buf);
                    System.out.println("recv:" + new String(buf, 0, len));
                    selectionKey.interestOps(selectionKey.interestOps() | SelectionKey.OP_WRITE);
                }
                else if (selectionKey.isWritable())
                {
                    int len = socketChannel.write(ByteBuffer.wrap("hey".getBytes()));
                    if (len == -1)
                    {
                        throw new RuntimeException("连接已断开");
                    }
                    selectionKey.interestOps(selectionKey.interestOps() & ~SelectionKey.OP_WRITE);
                    //这个只是控制一下发送数据的速度
                    Thread.sleep(1000);
                }
            }
        }
    }
}

