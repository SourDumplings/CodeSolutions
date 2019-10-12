import java.io.*;

public class BufferedWriterTester
{

	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		String fileName = "testBufferWriter.txt";
		BufferedWriter out = new BufferedWriter(new FileWriter(fileName));
		out.write("Hello!");
		out.newLine();
		out.write("Hello?");
		out.newLine();
		out.write("Hello...输入中文也可以");
		out.newLine();
		out.write("Hello.");
		out.close();
	}

}
