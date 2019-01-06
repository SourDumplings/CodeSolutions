import java.io.*;

public class BufferedOutputStreamTester
{

	public static void main(String[] args) throws IOException
	{
		String fileName = "mixedTypes.dat";
		DataOutputStream dataOut = new DataOutputStream(
				new BufferedOutputStream(
						new FileOutputStream(fileName)));
		dataOut.writeInt(0);
		System.out.println(dataOut.size() + " bytes have been written.");
		dataOut.writeDouble(31.2);
		System.out.println(dataOut.size() + " bytes have been written.");
		dataOut.writeBytes("JAVA");
		System.out.println(dataOut.size() + " bytes have been written.");
		dataOut.close();

	}

}
