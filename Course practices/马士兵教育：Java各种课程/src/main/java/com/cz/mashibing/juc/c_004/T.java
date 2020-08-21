/**
 * synchronized�ؼ���
 * ��ĳ���������
 * @author mashibing
 */

package com.cz.mashibing.juc.c_004;

public class T {

	private static int count = 10;
	
	public synchronized static void m() { //�����ͬ��synchronized(FineCoarseLock.class)
		count--;
		System.out.println(Thread.currentThread().getName() + " count = " + count);
	}
	
	public static void mm() {
		synchronized(T.class) { //����һ������дsynchronized(this)�Ƿ���ԣ�
			count --;
		}
	}

}
