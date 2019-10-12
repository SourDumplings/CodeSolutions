import java.util.*;
import java.util.Scanner;

public class Main{
    
	public static void main(String[]args) {	
		//输入一个整数
		Scanner cin = new Scanner(System.in);
		final int n = cin.nextInt(); // 声明final才能在内部类中使用
		cin.close();
		
		//书写代码创建一个线程来计算并输出阶乘
		//不要额外定义类，只使用Thread与Runnable即可
		/***begin your code here***/
		
		new Thread(new Runnable()
		{
			@Override
			public void run()
			{
				int res = 1;
				for (int i = n; i > 0; --i)
					res *= i;
				System.out.println(res);
			}
		}).start();

		/***end your code***/
		//标记主线程结束
		System.out.println("Main thread ends.");		
		return;
	}

}
