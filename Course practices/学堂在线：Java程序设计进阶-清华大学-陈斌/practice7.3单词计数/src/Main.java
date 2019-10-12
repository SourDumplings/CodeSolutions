import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.lang.Integer;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in); 
		//此处需要定义一个HashMap(建议)
		/***begin your code here***/
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		/***end your code***/
		while(true) {
			String s = cin.nextLine();
			if("QUIT".equals(s)) break;
        	
			//以下完成统计及输出功能的代码
			/***begin your code here***/
			Integer i;
			if (map.containsKey(s))
				i = map.get(s) + 1;
			else
				i = 1;
			System.out.println(i - 1);
			map.put(s, i);
			/***end your code***/
		}
		cin.close();
	}
	
}
