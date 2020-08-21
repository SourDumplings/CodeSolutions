/**
 * ���ͬ��������ĸ���Ч�ķ�����ʹ��AtomXXX��
 * AtomXXX�౾��������ԭ���Եģ������ܱ�֤�����������������ԭ���Ե�
 * @author mashibing
 */
package com.cz.mashibing.juc.c_018_00_AtomicXXX;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;


public class T01_AtomicInteger {
	/*volatile*/ //int count1 = 0;
	
	AtomicInteger count = new AtomicInteger(0); 

	/*synchronized*/ void m() { 
		for (int i = 0; i < 10000; i++)
			//if count1.get() < 1000
			count.incrementAndGet(); //count1++
	}

	public static void main(String[] args) {
		T01_AtomicInteger t = new T01_AtomicInteger();

		List<Thread> threads = new ArrayList<Thread>();

		for (int i = 0; i < 10; i++) {
			threads.add(new Thread(t::m, "thread-" + i));
		}

		threads.forEach((o) -> o.start());

		threads.forEach((o) -> {
			try {
				o.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		});

		System.out.println(t.count);

	}

}
