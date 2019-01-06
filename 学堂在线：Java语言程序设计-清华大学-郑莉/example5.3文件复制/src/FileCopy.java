import java.io.*;
import java.util.Scanner;

public class FileCopy
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.println("Please input source file and dest file:");
		String src = sc.nextLine();
		System.out.println("src = " + src);
		String dst = sc.nextLine();
		System.out.println("dst = " + dst);
		new CopyMaker().copy(src, dst);
		sc.close();
	}

}

class CopyMaker
{
	String sourceName, destName;
	BufferedReader source;
	BufferedWriter dest;
	String line;
	
	private boolean openFiles()
	{
		try
		{
			source = new BufferedReader(new FileReader(sourceName));
		}
		catch (IOException iox)
		{
			System.out.println("Problem opening " + sourceName);
			return false;
		}
		try
		{
			dest = new BufferedWriter(new FileWriter(destName));
		}
		catch (IOException iox)
		{
			System.out.println("Problem opening " + destName);
			return false;
		}
		return true;
	}
	private boolean copyFiles()
	{
		try
		{
			while((line = source.readLine()) != null)
			{
				dest.write(line);
				dest.newLine();
			} 
		}
		catch (IOException iox)
		{
			System.out.println("Problem reading or writing");
			return false;
		}
		return true;
	}
	private boolean closeFiles()
	{
		boolean ret = true;
		try
		{
			source.close();
			dest.close();
		}
		catch (IOException iox)
		{
			System.out.println("Problem closing " + sourceName
					+ "or " + destName);
		}
		return ret;
	}
	public boolean copy(String src, String dst)
	{
		sourceName = src;
		destName = dst;
		return openFiles() && copyFiles() && closeFiles();
	}
}
