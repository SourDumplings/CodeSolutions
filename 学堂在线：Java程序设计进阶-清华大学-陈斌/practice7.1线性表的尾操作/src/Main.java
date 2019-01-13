import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

//表示指令的对象
class Cmd{
	int cmd;				//只能取值1~5
	int nOrIndexOrValue;	//cmd为1时，该域表示index
							//cmd为2时，该域表示value
							//cmd为3时，该域表示n
							//cmd为4时，该域忽略
							//cmd为5时，该域表示n
	Integer [] params;		//cmd为3时，该域含n个int
}

public class Main {
	public static void main(String[] args) {
		Cmd [] commands = getCmd();//获取指令序列
		
		//学员需要自行定义数据编写代码完成题目指定的任务
		/***being your code here****/
		Integer[] A = new Integer[10];
		int l = 0;
		for (int i = 0; i != commands.length; ++i)
		{
			Cmd c = commands[i];
			switch (c.cmd)
			{
			case 1:
			{
//				1 index：查询第index位置上的数，如果index非法，则输出-1
				if (c.nOrIndexOrValue > l || c.nOrIndexOrValue < 1)
				{
					System.out.println(-1);
				}
				else
				{
					System.out.println(A[c.nOrIndexOrValue-1]);
				}
				break;
			}
			case 2:
			{
//				2 value：将value插入到表的尾部
				if (l == A.length)
				{
					A = Arrays.copyOf(A, l * 2);
				}
				A[l++] = c.nOrIndexOrValue;
				break;
			}
			case 3:
			{
//				3 n v1 v2 ... vn:将v1到vn的n个数一次插入到表的尾部
				if (l + c.nOrIndexOrValue > A.length)
					A = Arrays.copyOf(A, l + c.nOrIndexOrValue);
				for (Integer num : c.params)
				{
					A[l++] = num;
				}
				break;
			}
			case 4:
			{
//				4: 删除表尾的一个数，如果表是空的，则什么都不做
				if (l > 0)
				{
					--l;
				}
				break;
			}
			case 5:
			{
//				5 n: 删除表尾的n个数，如果表中没有n个数，则将表中的数全部删除
				if (l <= c.nOrIndexOrValue)
					l = 0;
				else
					l -= c.nOrIndexOrValue;
				break;
			}
			}
		}
		/***end your code****/
	}

	//生成指令序列，学员可以无视
	public static Cmd[] getCmd(){
		Scanner cin = new Scanner(System.in);
		A = cin.nextInt();
		B = cin.nextInt();
		M = cin.nextInt();
		X = cin.nextInt();
		cin.close();
				
		int n = get();
		Cmd [] ret = new Cmd [n];
		ret[0] = new Cmd();
		ret[0].cmd = 3;
		ret[0].nOrIndexOrValue = get();
		ret[0].params = new Integer [ret[0].nOrIndexOrValue];
		for(int i=0;i!=ret[0].nOrIndexOrValue;++i) ret[0].params[i] = get();
		
		for(int i=1;i!=n;++i) {
			Cmd cmd = new Cmd();
			cmd.cmd = get()%5+1;
			switch(cmd.cmd) {
			case 1:
			case 2:cmd.nOrIndexOrValue=get();break;
			case 3:cmd.nOrIndexOrValue=get();cmd.params=new Integer[cmd.nOrIndexOrValue];for(int j=0;j!=cmd.nOrIndexOrValue;++j)cmd.params[j]=get();break;
			case 4:break;
			case 5:cmd.nOrIndexOrValue=get();break;
			}
			ret[i] = cmd;
		}
		return ret;
	}
	
	//学员可以无视
	private static int A,B,M,X;
	private static int get() {
		X = (A*X+B) % M;
		return X;
	}
}
