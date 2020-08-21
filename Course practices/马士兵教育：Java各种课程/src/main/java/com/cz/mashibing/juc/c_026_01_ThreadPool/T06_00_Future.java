/**
 * ��ʶfuture
 * �첽
 */
package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.util.concurrent.*;

public class T06_00_Future {
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		
		FutureTask<Integer> task = new FutureTask<>(()->{
			TimeUnit.MILLISECONDS.sleep(500);
			return 1000;
		}); //new Callable () { Integer call();}
		
		new Thread(task).start();
		
		System.out.println(task.get()); //����


	}
}
