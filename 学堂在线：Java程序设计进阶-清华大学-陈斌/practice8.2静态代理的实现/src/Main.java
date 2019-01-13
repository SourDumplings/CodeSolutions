import java.util.Scanner;

//接口，规定了方法
interface IPoint{
	public void println();	
}

//实现类，方法在此类中实现
class Point implements IPoint{
	//实现类的私有成员
	private int x;
	private int y;
	
	//实现类的构造器
	public Point(int x,int y) {
		this.x = x;
		this.y = y;
	}
	
	//实现类实现了接口的方法
	@Override
	public void println() {
		System.out.println("("+x+","+y+")");
	}
}

//代理类，出于某种理由，客户不能访问Point类，只能访问ProxyPoint类
class ProxyPoint implements IPoint{
	//代理类持有实现类的一个实例
	private Point point;
	
	//学员需要编写代理类的构造器	
	public ProxyPoint(int x,int y) {
		/***begin your code here***/
		if (point == null)
			point = new Point(x, y);
		/***end your code***/
	}
	
	//学员需要实现代理类的接口方法
	@Override
	public void println() {
		/***begin your code here***/
		point.println();
		/***end your code***/
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int x = cin.nextInt();
		int y = cin.nextInt();
		cin.close();
		
		//创建一个代理类，并调用相应的方法
		//此处模仿客户端操作，客户"只能"创建了代理类的实例
		//但是归根到底，是实现类的方法实现了指定功能
		IPoint pp = new ProxyPoint(x,y);
		pp.println();		
	}
}


