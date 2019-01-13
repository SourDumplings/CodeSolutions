import java.util.Scanner;

public class Main{
    //直接定义一个基本类型用于保存结果
    static int result = 0;
  
    //这个数组专门用于为同步提供对象
    //因为基本类型不能直接用于同步
    static int [] a = new int [0];
  
    public static void main(String[]args){
        //根据指定的方法生成输入
        int [] input = getInput();
                
        //对每一个输入的参数
        //利用匿名Thread与匿名Runnable创建并执行一个子线程
        for(final int n:input) {
        	new Thread(new Runnable() {@Override public void run() {
				//此处求取n的最小质因子，如果n是1，认为答案就是1
				int t = 1;
				for(int i=2;i!=n+1;++i)if(0==n%i){t=i;break;}
  
				//在此补全代码，将n的最小质因子（即上面求出的t）累加至result
  				//注意做同步
				/***begin your code here***/
  
				synchronized(a)
				{
					result += t;
				}
  
				/***end your code***/        			
			}}).start();        	
        }
        
        //主线程暂时不和子线程做任何同步，简单的等待300ms之后，直接输出result（当然这是有隐患的）
        try {Thread.sleep(300L);} catch (InterruptedException e) {e.printStackTrace();}
        synchronized(a)
        {
            System.out.println(result);
        }
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

