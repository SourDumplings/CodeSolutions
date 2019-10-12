import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		int N;
		Scanner sc = new Scanner(System.in);
		N = Integer.parseInt(sc.nextLine().trim());
		String[] sData;
		for (int i = 0; i != N; ++i)
		{
			String line = sc.nextLine();
			sData = line.trim().split(" ");
			if (sData.length == 4)
			{
				Teacher t = new Teacher(sData);
				t.output();
			}
			else
			{
				Student s = new Student(sData);
				s.output();
			}
		}
		sc.close();
	}

}

class Person
{
	public String[] sData;
	Person(String[] sData)
	{
		this.sData = sData;
	}
	public int getMean()
	{
		int sum = 0;
		for (String s : sData)
		{
			sum += Integer.parseInt(s);
		}
		return sum / sData.length;
	}
}

class Student extends Person
{
	Student(String[] sData)
	{
		super(sData);
	}
	public void output()
	{
		System.out.println("Student " + getMean());
		return;
	}
}

class Teacher extends Person
{
	Teacher(String[] sData)
	{
		super(sData);
	}
	public void output()
	{
		System.out.println("Teacher " + getMean());
		return;
	}
}
