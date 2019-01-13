import java.util.*;
public class Main{
    public static void main(String [] args){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        cin.close();
          
        //创建一个MyThread的实例，并且在新的线程中执行
        new MyThread(n).start();
        System.out.println("Main thread ends.");
    }
}
  
class MyThread extends Thread{
    private int num;//私有成员
    //请在以下实现构造器并覆写run方法
    /***begin your code here***/
    public MyThread(int num)
    {
    	this.num = num;
    }
    
    public void run()
    {
    	int res = 1;
    	int i;
    	for (i = num; i > 0; --i)
    		res *= i;
    	System.out.println(res);
    }
    /***end your code***/
}
  