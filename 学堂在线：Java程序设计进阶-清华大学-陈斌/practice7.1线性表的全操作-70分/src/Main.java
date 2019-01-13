import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

//表示指令的对象
class Cmd{
	int cmd; 		//只能取值1~5
	int index;		//操作的位置
	int nOrValue;	//cmd为1时，该域无用
					//cmd为2时，该域表示value
					//cmd为3时，该域无用
					//cmd为4时，该域表示n
					//cmd为5时，该域表示n
	Integer [] params;	//cmd为4时，该域含n个int
}

public class Main {
	public static void main(String[] args) {
		Cmd [] commands = getCmd();//获取指令序列

		//学员需要自行定义数据以及设计程序以完成题目指定的任务
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
				if (c.index > l || c.index < 1)
				{
					System.out.println(-1);
				}
				else
				{
					System.out.println(A[c.index-1]);
				}
				break;
			}
			case 2:
			{
//				2 index value：在第index位置上插入一个数value，原来的数依次后移，如果index非法则不操作
				if (c.index <= l + 1 && c.index > 0)
				{
					if (l == A.length)
						A = Arrays.copyOf(A, l * 2);
					for (int j = l; j >= c.index; --j)
						A[j] = A[j-1];
					A[c.index-1] = c.nOrValue;
					++l;
				}
				break;
			}
			case 3:
			{
//				3 index：删除第index位置上的数，其后的数依次前移。如果index非法则不操作
				if (c.index <= l && c.index > 0)
				{
					for (int j = c.index - 1; j < l - 1; ++j)
						A[j] = A[j+1];
					--l;
				}
				break;
			}
			case 4:
			{
//				4 index n v1 v2 ... vn：从第index位置依次插入v1到vn的n个数，原来的数后移。如果index非法则不操作。
				if (c.index <= l + 1 && c.index > 0)
				{
					if (l + c.nOrValue > A.length)
						A = Arrays.copyOf(A, l + c.nOrValue);
					for (int j = l - 1 + c.nOrValue; j >= c.index - 1 + c.nOrValue; --j)
						A[j] = A[j - c.nOrValue];
					for (int j = 0; j != c.nOrValue; ++j)
						A[c.index - 1 + j] = c.params[j];
					l += c.nOrValue;
				}
				break;
			}
			case 5:
			{
//				5 index n: 从第index位置往后依次删除n个数，其后的数依次前移。
//				如果index非法则不操作，如果index及其之后不够n个数，则将index及其之后的数全部删除即可。
				if (c.index <= l && c.index > 0)
				{
					if (c.index - 1 + c.nOrValue < l)
					{
						for (int j = c.index - 1; j + c.nOrValue < l; ++j)
							A[j] = A[j + c.nOrValue];
						l -= c.nOrValue;
					}
					else
					{
						l = c.index - 1;
					}
				}
				break;
			}
			}
		}



		/***end your code****/
	}

	//生成指令序列，学员可以无视
	public static Cmd [] getCmd(){
		Scanner cin = new Scanner(System.in);
		A = cin.nextInt();
		B = cin.nextInt();
		M = cin.nextInt();
		X = cin.nextInt();
		cin.close();

		int n = get();
		Cmd [] ret = new Cmd [n];
		ret[0] = new Cmd();
		ret[0].cmd = 4;
		ret[0].index = 1;
		ret[0].nOrValue = get();
		ret[0].params = new Integer[ret[0].nOrValue];
		for(int i=0;i!=ret[0].nOrValue;++i) ret[0].params[i] = get();

		for(int i=1;i!=n;++i) {
			Cmd cmd = new Cmd();
			cmd.cmd = get()%5+1;
			switch(cmd.cmd) {
			case 1:cmd.index=get();break;
			case 2:cmd.index=get();cmd.nOrValue=get();break;
			case 3:cmd.index=get();break;
			case 4:cmd.index=get();cmd.nOrValue=get();cmd.params=new Integer [cmd.nOrValue];for(int j=0;j!=cmd.nOrValue;++j)cmd.params[j]=get();break;
			case 5:cmd.index=get();cmd.nOrValue=get();break;
			}
			ret[i]=cmd;
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


