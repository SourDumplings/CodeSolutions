import java.io.*;

public class FileOutputStreamTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		String fileName = "data.dat";
		int value0 = 255, value1 = 0, value2 = -1;
		try
		{
			DataOutputStream out = new DataOutputStream(
					new FileOutputStream(fileName));
			out.writeInt(value0);
			out.writeInt(value1);
			out.writeInt(value2);
			out.close();
		}
		catch (IOException iox)
		{
			System.out.println("Problem writing " + fileName);
		}
	}

}
