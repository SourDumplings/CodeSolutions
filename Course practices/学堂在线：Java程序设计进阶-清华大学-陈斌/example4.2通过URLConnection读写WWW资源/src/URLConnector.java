import java.net.*;
import java.io.*;

public class URLConnector
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		try
		{
			URL cs = new URL("http://www.sun.com/");
			URLConnection tc = cs.openConnection();
			BufferedReader in = new BufferedReader(
					new InputStreamReader(tc.getInputStream()));
			String inputLine;
			while ((inputLine = in.readLine()) != null)
				System.out.println(inputLine);
			in.close();
		}
		catch (MalformedURLException e)
		{
			System.out.println("MalformedURLException");
		}
		catch (IOException e)
		{
			System.out.println("IOException");
		}
	}

}
