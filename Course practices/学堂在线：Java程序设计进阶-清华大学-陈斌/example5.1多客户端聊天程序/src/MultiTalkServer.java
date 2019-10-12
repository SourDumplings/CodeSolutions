import java.io.*;
import java.net.*;

public class MultiTalkServer
{
	static int clientNum = 0;
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		ServerSocket serverSocket = null;
		boolean listening = true;
		try
		{
			serverSocket = new ServerSocket(6666);
			System.out.println("Server activated.");
		}
		catch (IOException e)
		{
			System.out.println("Could not listen on port: 6666");
			System.exit(-1);
		}
		while (listening)
		{
			new ServerThread(serverSocket.accept(), clientNum).start();
			++clientNum;
		}
		serverSocket.close();
		System.out.println("Server closed.");
		
	}

}


class ServerThread extends Thread
{
	Socket socket = null;
	int clientNum;
	public ServerThread(Socket socket, int num)
	{
		this.socket = socket;
		this.clientNum = num + 1;
	}
	public void run()
	{
		System.out.println("Client " + clientNum + " online.");
		try
		{
			String line;
			BufferedReader is = new BufferedReader(
					new InputStreamReader(socket.getInputStream()));
			PrintWriter os = new PrintWriter(
					socket.getOutputStream());
			BufferedReader sin = new BufferedReader(
					new InputStreamReader(System.in));
			System.out.println("Client " + clientNum +
					": " + is.readLine());
			line = sin.readLine();
			while (!line.equals("bye"))
			{
				os.println(line);
				os.flush();
				System.out.println("Server: " + line);
				System.out.println("Client " + clientNum +
						": " + is.readLine());
				line = sin.readLine();
			}
			os.close();
			is.close();
			socket.close();
			System.out.println("Client " + clientNum + "offline");
		}
		catch (Exception e)
		{
			System.out.println("Error: " + e);
		}
	}
}
