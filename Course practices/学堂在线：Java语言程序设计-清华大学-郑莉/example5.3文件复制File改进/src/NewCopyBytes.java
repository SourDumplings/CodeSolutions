import java.io.*;
import java.util.Scanner;

public class NewCopyBytes
{

	public static void main(String[] args)
	{
		DataInputStream instr;
		DataOutputStream outstr;
		System.out.println("Please input src and dst file:");
		Scanner sc = new Scanner(System.in);
		String src, dst;
		src = sc.nextLine();
		System.out.println("src = " + src);
		dst = sc.nextLine();
		System.out.println("dst = " + dst);
		sc.close();
		
		File inFile = new File(src);
		File outFile = new File(dst);
		boolean flag = true;
		if (!inFile.exists())
		{
			System.out.println(src + " doesn't exsits");
			flag = false;
		}
		if (outFile.exists())
		{
			System.out.println(dst + " already exists");
			flag = false;
		}
		
		if (flag)
		{
			try
			{
				instr = new DataInputStream(
						new BufferedInputStream(new FileInputStream(src)));
				outstr = new DataOutputStream(
						new BufferedOutputStream(new FileOutputStream(dst)));
				try
				{
					int data;
					while (true)
					{
						data = instr.readUnsignedByte();
						outstr.writeByte(data);
					}
				}
				catch (EOFException eof)
				{
					outstr.close();
					instr.close();
					System.out.println("Copying finished");
					return;
				}
			}
			catch (IOException iox)
			{
				System.out.println("IO Problem");
			}
		}
	}

}
