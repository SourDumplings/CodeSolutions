import java.util.*;
public class Main{
    public static void main(String [] args){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        cin.close();

        //利用MyRunnable实例创建一个Thread实例
        //并且在新的线程中执行
        new Thread(new MyRunnable(n)).start();
        System.out.println("Main thread ends.");        
    }
}
class MyRunnable implements Runnable{
    private int num;//私有成员
    //在以下实现MyRunnable的构造方法以及覆写run方法
    /***begin your code here***/
    public MyRunnable(int n)
    {
    	this.num = n;
    }
    
    public void run()
    {
    	int res = 1;
    	int i;
    	for (i = num; i > 0; --i)
    		res *= i;
    	System.out.println(res);
    	return;
    }


    /***end your code***/
}
