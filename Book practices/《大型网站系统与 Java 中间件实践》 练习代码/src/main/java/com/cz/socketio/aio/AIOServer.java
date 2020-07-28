package com.cz.socketio.aio;


import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.AsynchronousServerSocketChannel;
import java.nio.channels.AsynchronousSocketChannel;
import java.nio.channels.CompletionHandler;

/**
 * @author changzheng
 * @version 1.0.0
 * @projectName 《大型网站系统与 Java 中间件实践》 练习代码
 * @date 2020/7/28 16:46
 */
public class AIOServer
{
    public static void main(String[] args) throws IOException, InterruptedException
    {
        //创建异步服务端通道 & 绑定host:port
        AsynchronousServerSocketChannel serverSocketChannel = AsynchronousServerSocketChannel.open()
            .bind(new InetSocketAddress(9999));
        //异步accept客户端请求，第一个参数是附加参数，透传进去的，可以为null
        //第二个参数是异步处理，回调的时候会调用里面的方法
        serverSocketChannel.accept(serverSocketChannel, new AcceptHandle());
        //main线程阻塞
        while (true)
        {
            Thread.sleep(10000);
        }
    }

    //accept事件处理
    static class AcceptHandle implements
        CompletionHandler<AsynchronousSocketChannel, AsynchronousServerSocketChannel>
    {

        //当有客户端请求进来，会自动回调这个方法
        @Override
        public void completed(AsynchronousSocketChannel socketChannel,
            AsynchronousServerSocketChannel serverSocketChannel)
        {
            //异步处理读事件，其中第一个参数是Buffer，用来存放读取的数据
            //第二个参数是附加参数，一直透传，啥也不干
            //第三个参数是异步处理读结果的类，当读成功或者失败的时候，会回调里面的方法
            ChannelInfo channelInfo = new ChannelInfo(socketChannel);
            socketChannel.read(channelInfo.getReadBuffer(), channelInfo, new ReadHandle());
            serverSocketChannel.accept(serverSocketChannel, this);
        }

        @Override
        public void failed(Throwable throwable, AsynchronousServerSocketChannel serverSocketChannel)
        {
            throwable.printStackTrace();
        }
    }

    //read事件处理
    static class ReadHandle implements CompletionHandler<Integer, ChannelInfo>
    {

        //当读成功时会回调(只要不报错，都算是成功)
        @Override
        public void completed(Integer integer, ChannelInfo channelInfo)
        {
            //读取长度大于0再处理
            if (integer > 0)
            {
                //channel Buffer正常操作
                ByteBuffer buffer = channelInfo.getReadBuffer();
                buffer.flip();
                byte[] buf = new byte[buffer.remaining()];
                buffer.get(buf);
                buffer.clear();
                System.out.println("recv:" + new String(buf));
                //异步写，参数和read参数一模一样
                channelInfo.getWriteBuffer().put(buf);
                channelInfo.getWriteBuffer().flip();
                channelInfo.getSocketChannel()
                    .write(channelInfo.getWriteBuffer(), channelInfo, new WriteHandle());
            }
            //这一步一定要有，否则就只能接收到一次
            //其实说白了，你想异步读数据，那么就传一个人家规定好的回调方法，完成的时候，让他自动的去调用你这个方法
            //所以，每读一次，都需要传一次
            channelInfo.getSocketChannel().read(channelInfo.getReadBuffer(), channelInfo, this);
        }

        @Override
        public void failed(Throwable throwable, ChannelInfo channelInfo)
        {
            throwable.printStackTrace();
        }
    }

    //write时间处理
    static class WriteHandle implements CompletionHandler<Integer, ChannelInfo>
    {

        //写完成后，会调用这个方法
        @Override
        public void completed(Integer integer, ChannelInfo channelInfo)
        {
            System.out.println("write bytes：" + integer);
            channelInfo.getWriteBuffer().clear();
        }

        @Override
        public void failed(Throwable throwable, ChannelInfo channelInfo)
        {
            throwable.printStackTrace();
        }
    }

    static class ChannelInfo
    {
        AsynchronousSocketChannel socketChannel;
        ByteBuffer readBuffer;
        ByteBuffer writeBuffer;

        public ChannelInfo(AsynchronousSocketChannel socketChannel)
        {
            this.socketChannel = socketChannel;
            this.readBuffer = ByteBuffer.allocate(32);
            this.writeBuffer = ByteBuffer.allocate(32);
        }

        public AsynchronousSocketChannel getSocketChannel()
        {
            return socketChannel;
        }

        public void setSocketChannel(AsynchronousSocketChannel socketChannel)
        {
            this.socketChannel = socketChannel;
        }

        public ByteBuffer getReadBuffer()
        {
            return readBuffer;
        }

        public void setReadBuffer(ByteBuffer readBuffer)
        {
            this.readBuffer = readBuffer;
        }

        public ByteBuffer getWriteBuffer()
        {
            return writeBuffer;
        }

        public void setWriteBuffer(ByteBuffer writeBuffer)
        {
            this.writeBuffer = writeBuffer;
        }
    }
}
