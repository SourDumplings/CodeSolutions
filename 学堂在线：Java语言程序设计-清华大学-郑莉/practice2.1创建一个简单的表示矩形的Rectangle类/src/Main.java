import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Rectangle r = new Rectangle();
		Scanner sc = new Scanner(System.in); 
		r.height = sc.nextInt();
		r.width = sc.nextInt();
		sc.close();
		System.out.println(r.getArea() + " " + r.getPerimeter());
		return;
	}

}

class Rectangle
{
	int height, width;
	public int getArea()
	{
		return height * width;
	}
	public int getPerimeter()
	{
		return 2 * (height + width);
	}
}
