package com.cz.socketio.nio;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/28 14:48
 */
public class NIOServer
{
    public static void main(String[] args) throws IOException
    {
        //创建服务端socket通道 & 绑定host:port
        ServerSocketChannel serverSocketChannel = ServerSocketChannel.open()
            .bind(new InetSocketAddress(9999));
        //设置为非阻塞模式
        serverSocketChannel.configureBlocking(false);
        //新创建一个selector（其实可以为每一个channel单独创建一个selector）
        Selector selector = Selector.open();
        //将该通道注册到该selector上，并且注明感兴趣的事件，因为是服务端通道，所以只对accept事件感兴趣
        serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
        while (true)
        {
            //selector会帮我们去轮询，当前是否有我们感兴趣的事件发生，一直阻塞到有为止
            //select还有一个方法，可以指定阻塞时间，超过这个时间就会返回，此时可能返回的key个数为0
            selector.select();
            //若返回的key个数不为0，那么就可以一一处理这些事件
            Set<SelectionKey> selectionKeys = selector.selectedKeys();
            Iterator<SelectionKey> iterator = selectionKeys.iterator();
            while (iterator.hasNext())
            {
                SelectionKey selectionKey = iterator.next();
                //remove是为了下一次select的时候，避免重复处理这些已经处理过的事件
                //什么意思呢？其实selector.selectedKeys()返回来的set，就是其
                //内部操作的set，引用的是同一个set，所以我们如果不在外面remove已经
                //处理的事件，那么下一次，还会再次出现。需要注意的是，如果在外面对set
                //进行add操作，会抛异常，简单的说就是在外只删不增，在内只增不删。
                iterator.remove();
                //SelectionKey.OP_ACCEPT事件
                if (selectionKey.isAcceptable())
                {
                    SocketChannel socketChannel = ((ServerSocketChannel) selectionKey.channel())
                        .accept();
                    socketChannel.configureBlocking(false);
                    socketChannel.register(selector, SelectionKey.OP_READ);
                    //SelectionKey.OP_READ事件
                }
                else if (selectionKey.isReadable())
                {
                    //selectionKey.channel()返回的SelectableChannel是SocketChannel的父类
                    //所以可以直接强转
                    SocketChannel socketChannel = (SocketChannel) selectionKey.channel();
                    //NIO规定，必须要用Buffer进行读写
                    ByteBuffer buffer = ByteBuffer.allocate(32);
                    int len = socketChannel.read(buffer);
                    if (len == -1)
                    {
                        throw new RuntimeException("连接已断开");
                    }
                    //上面那一步只是读到缓冲区，这里是从缓冲区真正的拿出数据
                    byte[] buf = new byte[len];
                    //这个操作可以举个例子
                    //例如read(buffer)的时候，其实内部是调用了buffer.put这个方法
                    //那么read结束，position的位置必定等于len
                    //所以我们必须重置一下position为0，才可以从头开始读，但是读到什么地方呢？
                    //那就需要设置limit = position，所以flip后，position=0， limit = len
                    buffer.flip();
                    buffer.get(buf);
                    System.out.println("recv:" + new String(buf, 0, len));
                    //注册写事件
                    selectionKey.interestOps(selectionKey.interestOps() | SelectionKey.OP_WRITE);
                    //SelectionKey.OP_WRITE事件
                }
                else if (selectionKey.isWritable())
                {
                    SocketChannel socketChannel = (SocketChannel) selectionKey.channel();
                    //写数据，也要用Buffer来写
                    int len = socketChannel.write(ByteBuffer.wrap("hello".getBytes()));
                    if (len == -1)
                    {
                        throw new RuntimeException("连接已断开");
                    }
                    //这里为什么要取消写事件呢？因为只要底层的写缓冲区不满，就会一直收到这个事件
                    //所以只有想写数据的时候，才要注册这个写事件
                    selectionKey.interestOps(selectionKey.interestOps() & ~SelectionKey.OP_WRITE);
                }
            }
        }
    }
}

