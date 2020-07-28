package com.cz.socketio.buffer;

import java.nio.ByteBuffer;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/28 15:38
 */
public class BufferTest
{
    public static void main(String[] args)
    {
        //分配32个字节大小的空间
        ByteBuffer buffer = ByteBuffer.allocate(32);
        //需要写入的字节数组
        byte[] writeBuf = "hello".getBytes();
        //调用put将数据写入缓冲区
        buffer.put(writeBuf);
        //重置position和limit，为下一次的读做准备
        buffer.flip();
        byte[] readBuf = new byte[5];
        //将缓冲区的数据读到readBuf数组中
        buffer.get(readBuf);
        System.out.println(new String(readBuf));

    }
}
