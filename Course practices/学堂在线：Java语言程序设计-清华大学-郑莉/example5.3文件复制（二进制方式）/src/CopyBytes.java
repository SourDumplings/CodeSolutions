import java.io.*;
import java.util.Scanner;

public class CopyBytes
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
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
		catch (FileNotFoundException nfx)
		{
			System.out.println("Problem opening files");
		}
		catch (IOException iox)
		{
			System.out.println("IO Problem");
		}
	}

}
