import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
	public static void main(String[] args) throws Exception{
		//根据指定的方法生成输入
		int [] input = getInput();
        
		//使用AtomicInteger的实例来保存结果
		//后续代码就无需synchronized，也无需lock
		//当然，需要正确调用AtomicInteger的成员方法
		final AtomicInteger result = new AtomicInteger(0);    
        
		//对每一个输入的参数，创建并执行一个子线程
		//与之前的某个作业类似，这里需要保证主线程与子线程之间的同步
		//即必须等子线程全部完成之后，才在主线程打印结果
		for(final int n:input) {
 			Thread thread = new Thread(new Runnable(){@Override public void run(){
  				int t = 1;
  				for(int i=2;i!=n+1;++i)if(0==n%i){t=i;break;}
  				//此处将结果累加至result			
				/***begin your code here***/
  				result.addAndGet(t);
				/***end your code***/				
  			}});      	
  			//执行线程，并通知主线程进行等待
  			thread.start();
    		thread.join();
		}
        System.out.println(result.get());
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

