package urlConnection.post;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.CookieHandler;
import java.net.CookieManager;
import java.net.CookiePolicy;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Properties;
import java.util.Scanner;

/**
 * This program demonstrates how to use the URLConnection class for a POST request.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/28 8:56
 */
public class PostTest
{
    public static void main(String[] args) throws IOException
    {
        String propsFilename = "./CZ/resources/post.properties";
        Properties props = new Properties();
        try (final InputStream in = Files.newInputStream(Paths.get(propsFilename)))
        {
            props.load(in);
        }
        final String urlString = props.remove("url").toString();
        final Object userAgent = props.remove("User-Agent");
        final Object redirects = props.remove("redirects");
        CookieHandler.setDefault(new CookieManager(null, CookiePolicy.ACCEPT_ALL));
        final String result = doPost(new URL(urlString), props,
            userAgent == null ? null : userAgent.toString(),
            redirects == null ? -1 : Integer.parseInt(redirects.toString()));
        System.out.println(result);
    }

    /**
     * Do a HTTP POST.
     *
     * @param url
     * @param nameValuePairs
     * @param userAgent
     * @param redirects
     * @return the data returned from the server
     * @throws IOException
     */
    public static String doPost(URL url, Map<Object, Object> nameValuePairs, String userAgent,
        int redirects) throws IOException
    {
        final HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        if (userAgent != null)
        {
            connection.setRequestProperty("User-Agent", userAgent);
        }

        if (redirects >= 0)
        {
            connection.setInstanceFollowRedirects(false);
        }

        // 打开输出流
        connection.setDoOutput(true);

        try (PrintWriter out = new PrintWriter(connection.getOutputStream()))
        {
            boolean first = true;
            for (Entry<Object, Object> pair : nameValuePairs.entrySet())
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.print("&");
                }
                final String name = pair.getKey().toString();
                final String value = pair.getValue().toString();
                out.print(name);
                out.print("=");
                out.print(URLEncoder.encode(value, "UTF-8"));
            }
        }

        String encoding = connection.getContentEncoding();
        if (encoding == null)
        {
            encoding = "UTF-8";
        }

        // 人工重定向
        if (redirects > 0)
        {
            final int responseCode = connection.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_MOVED_PERM ||
                responseCode == HttpURLConnection.HTTP_MOVED_TEMP ||
                responseCode == HttpURLConnection.HTTP_SEE_OTHER)
            {
                final String location = connection.getHeaderField("Location");
                if (location != null)
                {
                    final URL base = connection.getURL();
                    connection.disconnect();
                    return doPost(new URL(base, location), nameValuePairs, userAgent,
                        redirects - 1);
                }
            }
        }
        else if (redirects == 0)
        {
            throw new IOException("Too many redirects");
        }

        final StringBuilder response = new StringBuilder();
        try (final Scanner in = new Scanner(connection.getInputStream(), encoding))
        {
            while (in.hasNextLine())
            {
                response.append(in.nextLine());
                response.append("\n");
            }
        }
        catch (IOException e)
        {
            InputStream err = connection.getErrorStream();
            if (err == null)
            {
                throw e;
            }
            try (final Scanner in = new Scanner(err))
            {
                response.append(in.nextLine());
                response.append("\n");
            }
        }
        return response.toString();
    }
}
