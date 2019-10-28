package urlConnection;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

/**
 * This program connects to an URL and displays the response header data and the first 10 lines of
 * the requested data.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/27 20:49
 */
public class URLConnectionTest
{
    public static void main(String[] args)
    {
        System.out.println("Please input URL, username and password, separated by space:");
        try (Scanner sc = new Scanner(System.in))
        {
            String line = sc.nextLine();
            final String[] lineStrs = line.split(" ");

            String urlName;
            if (!lineStrs[0].equals("") && lineStrs.length > 0)
            {
                urlName = lineStrs[0];
            }
            else
            {
                urlName = "http://horstmann.com";
            }

            URL url = new URL(urlName);
            final URLConnection connection = url.openConnection();

            if (lineStrs.length > 2)
            {
                final String username = lineStrs[1];
                final String password = lineStrs[2];
                String input = username + ":" + password;
                Base64.Encoder encoder = Base64.getEncoder();
                final String encoding = encoder
                    .encodeToString(input.getBytes(StandardCharsets.UTF_8));
                connection.setRequestProperty("Authorization", "Basic " + encoding);
            }
            connection.connect();

            // print header fields
            final Map<String, List<String>> headers = connection.getHeaderFields();
            for (Entry<String, List<String>> entry : headers.entrySet())
            {
                String key = entry.getKey();
                for (String value : entry.getValue())
                {
                    System.out.println(key + ":" + value);
                }
            }

            // print convenient functions
            System.out.println("-----------");
            System.out.println("getContentType: " + connection.getContentType());
            System.out.println("getContentLength: " + connection.getContentLength());
            System.out.println("getContentEncoding: " + connection.getContentEncoding());
            System.out.println("getDate: " + connection.getDate());
            System.out.println("getExpiration: " + connection.getExpiration());
            System.out.println("getLastModified: " + connection.getLastModified());
            System.out.println("-----------");

            String contentEncoding = connection.getContentEncoding();
            if (contentEncoding == null)
            {
                contentEncoding = "UTF-8";
            }
            try (Scanner in = new Scanner(connection.getInputStream(), contentEncoding))
            {
                // print first ten lines of contents
                for (int i = 0; in.hasNextLine() && i <= 10; i++)
                {
                    System.out.println(in.nextLine());
                }
                if (in.hasNextLine())
                {
                    System.out.println(". . .");
                }
            }

        }
        catch (MalformedURLException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
