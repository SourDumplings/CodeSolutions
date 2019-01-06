import java.io.*;
import java.util.Scanner;

public class FileTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		File f = new File("Hello.txt");
		boolean isCreate = true;
		if (f.exists())
		{
			System.out.println(f.getName() +
					" already exists. Delete it and create new one('y'/'Y' means Yes)?");
			Scanner sc = new Scanner(System.in);
			String ans = sc.nextLine();
			if (ans.equals("Y") || ans.equals("y"))
			{
				f.delete();
			}
			else
				isCreate = false;
		}
		if (isCreate)
		{
			try
			{
				f.createNewFile();
			}
			catch (Exception e)
			{
				System.out.println(e.getMessage());
			}
		}
	}

}
