import java.io.*;

public class FileWriterTester
{

	public static void main(String[] args)
	{
		String fileName = "testFileWriter.txt";
		try
		{
			FileWriter write = new FileWriter(fileName, false);
			write.write("Hello?\n");
			write.write("Hello!\n");
			write.write("Hello...输入中文也可以\n");
			write.write("Hello.\n");
			write.close();
		}
		catch (IOException iox)
		{
			System.out.println("Problem writing " + fileName);
		}
		// TODO Auto-generated method stub

	}

}
