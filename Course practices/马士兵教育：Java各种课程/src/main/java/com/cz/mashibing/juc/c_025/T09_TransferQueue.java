package com.cz.mashibing.juc.c_025;

import java.util.concurrent.LinkedTransferQueue;

public class T09_TransferQueue
{
    public static void main(String[] args) throws InterruptedException
    {
        LinkedTransferQueue<String> strs = new LinkedTransferQueue<>();

        new Thread(() ->
        {
            try
            {
                System.out.println(strs.take());
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }).start();

        strs.transfer("aaa"); // 用 transfer 是装完阻塞，别人取走了才能继续
		// 这是确保客户已经处理信息的一种机制

        //strs.put("aaa"); // 用 put 就是装完就走


		/*new Thread(() -> {
			try {
				System.out.println(strs.take());
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}).start();*/

    }
}
