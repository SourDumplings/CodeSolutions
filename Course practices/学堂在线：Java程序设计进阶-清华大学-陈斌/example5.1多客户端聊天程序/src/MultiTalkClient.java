import java.io.*;
import java.net.*;

public class MultiTalkClient
{
	int num;
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		try
		{
			Socket socket = new Socket("127.0.0.1", 6666);
			BufferedReader sin = new BufferedReader(
					new InputStreamReader(System.in));
			PrintWriter os = new PrintWriter(socket.getOutputStream());
			BufferedReader is = new BufferedReader(
					new InputStreamReader(socket.getInputStream()));
			String line;
			line = sin.readLine();
			while (!line.equals("bye"))
			{
				os.println(line);
				os.flush();
				System.out.println("Client: " + line);
				System.out.println("Server: " + is.readLine());
				line = sin.readLine();
			}
			os.close();
			is.close();
			socket.close();
		}
		catch (Exception e)
		{
			System.out.println("Error: " + e);
		}
	}

}
