import java.io.*;
import java.net.*;

public class TalkClient
{
	public static void main(String[] args)
	{
		try
		{
			Socket socket = new Socket("127.0.0.1", 7777);
			BufferedReader sin = new BufferedReader(new
					InputStreamReader(System.in)); // 键盘输入流
			// 输出流，把信息从客户端发送给服务端
			PrintWriter os = new PrintWriter(new OutputStreamWriter(
					socket.getOutputStream()));
			// 输入流，接收网络上发给我这个程序的信息
			BufferedReader is = new BufferedReader(new
					InputStreamReader(socket.getInputStream()));
			
			String readLine;
			readLine = sin.readLine();
			while (!readLine.equals("bye"))
			{
				os.println(readLine);
				os.flush();
				System.out.println("Client: " + readLine);
				System.out.println("Server: " + is.readLine());
				readLine = sin.readLine();
			}
			os.close();
			is.close();
			socket.close();
		}
		catch (Exception e)
		{
			System.out.println("Error " + e);
		}
	}
}
