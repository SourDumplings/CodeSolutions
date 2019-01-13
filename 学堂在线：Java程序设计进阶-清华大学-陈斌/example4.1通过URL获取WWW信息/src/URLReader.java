import java.net.*;
import java.io.*;

public class URLReader
{

	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
		URL cs = new URL("http://www.sun.com/");
		BufferedReader in = new BufferedReader(
				new InputStreamReader(cs.openStream()));
		String inputLine;
		while ((inputLine = in.readLine()) != null)
			System.out.println(inputLine);
		in.close();
	}

}
