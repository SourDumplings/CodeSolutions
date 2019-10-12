import java.util.Scanner;

class Result{
	//本题学员的任务就是补全Result类，使整个程序能够正确的运行
	/***begin your code here***/
	private int res = 0;
	public Result(int n) { res = n; }
	public synchronized void addValue(int t)
	{
		res += t;
	}
	public synchronized int getValue()
	{
		return res;
	}
	
	/***end your code***/
}

public class Main{
    public static void main(String[]args){
        //根据指定的方法生成输入
        int [] input = getInput();
        
        //定义一个Result实例，用于保存计算结果
        final Result result = new Result(0);
        
        //对每一个输入的参数
        //利用匿名Thread与匿名Runnable创建并执行一个子线程
        for(final int n:input) {
        	new Thread(new Runnable() {@Override public void run() {
				//此处求取n的最小质因子，如果n是1，认为答案就是1
				int t = 1;
				for(int i=2;i!=n+1;++i)if(0==n%i){t=i;break;}
				//t就是答案，将t累加进result
				result.addValue(t);
			}}).start();        	
        }
        
        //主线程暂时不和子线程做任何同步，简单的等待300ms之后，直接输出result(这样做当然是由隐患的)
        try {Thread.sleep(300L);}catch (InterruptedException e) {e.printStackTrace();}
        System.out.println(result.getValue());
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

