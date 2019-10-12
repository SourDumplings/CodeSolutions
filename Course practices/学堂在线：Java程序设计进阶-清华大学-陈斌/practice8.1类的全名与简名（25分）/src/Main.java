import java.util.Scanner;
import java.lang.reflect.*;

public class Main {
	public static void main(String[] args) throws ClassNotFoundException,
	InstantiationException, IllegalAccessException {
		Scanner cin = new Scanner(System.in);
		String name = cin.nextLine();
		cin.close();
		//name表示一个类的全名，请输出该类的简名
		/***begin your code here***/
		Class cls = Class.forName(name);
		Object ap = cls.newInstance();
		System.out.println(ap.getClass().getSimpleName());
		/***end your code***/	
	}
}

