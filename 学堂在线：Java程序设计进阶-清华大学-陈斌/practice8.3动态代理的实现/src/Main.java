import java.util.Scanner;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

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

//动态代理类，学员请完整的完成整个动态代理类的内容
class DynamicProxyPoint implements InvocationHandler{
	/***begin your code here***/	
	private Object sub;
	public DynamicProxyPoint() {}
	public DynamicProxyPoint(Object obj)
	{
		sub = obj;
	}
	public Object invoke(Object proxy, Method method, Object[] args)
		throws Throwable
	{
		method.invoke(sub, args);
		return null;
	}
  
	/***end your code***/	
}

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int x = cin.nextInt();
		int y = cin.nextInt();
		cin.close();
		
		//被代理对象
		IPoint point = new Point(x,y);
		//创建一个与被代理对象关联的Handler
		InvocationHandler ih = new DynamicProxyPoint(point);
		//创建一个动态代理对象	
		IPoint proxy = (IPoint)Proxy.newProxyInstance(ih.getClass().getClassLoader(), Point.class.getInterfaces(), ih);
		//通过代理对象调用方法
		proxy.println();		
	}
}


