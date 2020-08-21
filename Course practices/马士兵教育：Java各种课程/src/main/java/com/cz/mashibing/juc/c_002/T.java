/**
 * synchronized�ؼ���
 * ��ĳ���������
 * @author mashibing
 */

package com.cz.mashibing.juc.c_002;

public class T {
	
	private int count = 10;
	
	public void m() {
		synchronized(this) { //�κ��߳�Ҫִ������Ĵ��룬�������õ�this����
			count--;
			System.out.println(Thread.currentThread().getName() + " count = " + count);
		}
	}
	
}

