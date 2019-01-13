import java.io.*;
import java.net.*;

public class TalkServer
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		try
		{
			ServerSocket server = null;
			try
			{
				int port = 7777;
				server = new ServerSocket(port);
				System.out.println("The server is listening on 7777...");
			}
			catch (Exception e)
			{
				System.out.println("cannot listen to: " + e);
			}
			Socket socket = null;
			try
			{
				socket = server.accept();
				System.out.println("Server: connection made");
			}
			catch (Exception e)
			{
				System.out.println("Error. " + e);
			}
			
			// 服务端构造三个流
			String line;
			// 输入流，来自客户端给它的信息
			BufferedReader is = new BufferedReader(
					new InputStreamReader(socket.getInputStream()));
			// 输出流，向客户端发送信息
			PrintWriter os = new PrintWriter(socket.getOutputStream());
			// 键盘输入流
			BufferedReader sin = new BufferedReader(
					new InputStreamReader(System.in));
		
			System.out.println("Client: " + is.readLine());
			line = sin.readLine();
			while (!line.equals("bye"))
			{
				os.println(line);
				os.flush();
				System.out.println("Server: " + line);
				System.out.println("Client: " + is.readLine());
				line = sin.readLine();
			}
			
//			// 服务端接收信息模拟
//			String line;
//			// 输入流，来自客户端给它的信息
//			BufferedReader is = new BufferedReader(
//					new InputStreamReader(socket.getInputStream()));
//			// 输出流，向客户端发送信息
//			PrintWriter os = new PrintWriter(new OutputStreamWriter(
//					socket.getOutputStream()));
//			// 键盘输入流
//			System.out.println("Server is going to process information.");
//			while (true)
//			{
//				line = is.readLine();
//				System.out.println("Client: " + line);
//				if (line.equals("bye"))
//					break;
//				line += " copied\n";
//				os.println(line);
//				os.flush();
//			}
//			System.out.println("Server stops processing information.");
			
			os.close();
			is.close();
			socket.close();
			System.out.println("Connection ends.");
			server.close();
			System.out.println("Listening ends.");
		}
		catch (Exception e)
		{
			System.out.println("Error: " + e);
		}
	}

}
