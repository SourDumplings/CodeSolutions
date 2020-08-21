package com.cz.mashibing.juc.c_025;

import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

public class T05_LinkedBlockingQueue {

	static BlockingQueue<String> strs = new LinkedBlockingQueue<>();

	static Random r = new Random();

	public static void main(String[] args) {
		new Thread(() -> {
			for (int i = 0; i < 100; i++) {
				try {
					strs.put("a" + i); //������ˣ��ͻ�ȴ�
					TimeUnit.MILLISECONDS.sleep(r.nextInt(1000));
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}, "p1").start();

		for (int i = 0; i < 5; i++) {
			new Thread(() -> {
				for (;;) {
					try {
						System.out.println(Thread.currentThread().getName() + " take -" + strs.take()); //������ˣ��ͻ�ȴ�
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}, "c" + i).start();

		}
	}
}
