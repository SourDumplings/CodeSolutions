import java.util.Scanner;
import java.lang.Exception;
import java.lang.InterruptedException;
public class Main {
    //直接定义一个基本类型用于保存结果
    static int result = 0;
    //这个数组专门用于为同步提供对象
    //因为基本类型不能直接用于同步
    static int [] a = new int [0];    
    public static void main(String[] args) {
		//根据指定的方法生成输入
		int [] input = getInput();
        
		//对每一个输入的参数，创建并执行一个子线程
		for(final int n:input) {
			//创建一个具名对象表示一个完成指定任务的线程
 			Thread thread = new Thread(new Runnable(){@Override public void run(){
				int t = 1;
 				for(int i=2;i!=n+1;++i)if(0==n%i){t=i;break;}
				//将t累加至结果，此处需要做同步
				synchronized(a){result+=t;}
  			}});
  			//执行该线程
  			thread.start();
  			//在这里敲入代码保证主线程能够正确等待直到所有子线程结束
			/***begin your code here***/  
        	try { thread.join(); } catch (Exception e) {}
			/***end your code***/
        }
        
        //要确保子线程结束以后才在主线程打印该结果
        //考虑一下在上面创建并执行子线程的时候，还应该做什么
        System.out.println(result);
	}

	
    //本方法用于生成输入参数，学员可以无视
    private static int [] getInput(){
    	Scanner cin = new Scanner(System.in);
    	int a = cin.nextInt();
    	int b = cin.nextInt();
    	int m = cin.nextInt();
    	int x = cin.nextInt();
    	cin.close();
    	
    	int [] ret = new int [100];
    	for(int i=0;i!=100;++i) {
    		x = ( a * x + b ) % m;
    		ret[i] = x;
    	}
    	return ret;
    }
}


