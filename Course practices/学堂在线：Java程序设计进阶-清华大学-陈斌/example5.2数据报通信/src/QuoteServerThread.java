import java.io.*;
import java.net.*;
import java.util.*;

public class QuoteServerThread extends Thread
{
	protected DatagramSocket socket = null;
	protected BufferedReader in = null;
	protected boolean moreQuotes = true;
	public QuoteServerThread() throws IOException
	{
		this("QuoteServerThread");
	}
	public QuoteServerThread(String name) throws IOException
	{
		super(name);
		socket = new DatagramSocket(6666);
		try
		{
			in = new BufferedReader(new FileReader(
					"one-liners.txt"));
		}
		catch (FileNotFoundException e)
		{
			System.out.println("Could not open quote file");
		}
	}
	public void run()
	{
		while (moreQuotes)
		{
			try
			{
				byte[] buf = new byte[256];
				DatagramPacket packet = new DatagramPacket(buf, buf.length);
				socket.receive(packet);
				String dString = null;
				if (in == null)
					dString = new Date().toString();
				else
					dString = getNextQuote();
				buf = dString.getBytes();
				// 发回客户端
				InetAddress address = packet.getAddress();
				int port = packet.getPort();
				packet = new DatagramPacket(buf, buf.length, address, port);
				socket.send(packet);
			}
			catch (IOException e)
			{
				e.printStackTrace();
				moreQuotes = false;
			}
		}
		socket.close();
	}
	protected String getNextQuote()
	{
		String ret = null;
		try
		{
			if ((ret = in.readLine()) == null)
			{
				in.close();
				moreQuotes = false;
				ret = "No more quotes. Goodbye";
			}
		}
		catch (IOException e)
		{
			ret = "IOException occured in server";
		}
		return ret;
	}
}
