import java.io.*;

public class Redirecting
{

	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		BufferedInputStream in = new BufferedInputStream(
				new FileInputStream("data.dat"));
		PrintStream out = new PrintStream(
				new BufferedOutputStream(new FileOutputStream("test.out")));
		System.setIn(in);
		System.setOut(out);
		System.setErr(out);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
		while ((s = br.readLine()) != null)
			System.out.println(s);
		in.close();
		out.close();
	}

}
