package com.cz.hello.httpclient;

import java.io.IOException;
import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-httpclient
 * @date 2020/1/11 21:51
 */
public class MyTestGet
{
    public static void main(String[] args)
    {
        get();
    }

    private static void get()
    {
        // 创建 HttpClient 客户端
        CloseableHttpClient httpClient = HttpClients.createDefault();

        // 创建 HttpGet 请求
        HttpGet httpGet = new HttpGet(
            "http://localhost:8080/content/page?draw=1&start=0&length=10");
        // 设置长连接
        httpGet.setHeader("Connection", "keep-alive");
        // 设置代理（模拟浏览器版本）
        httpGet.setHeader("User-Agent",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36");
        // 设置 Cookie
        httpGet.setHeader("Cookie",
            "Idea-6a318e28=19bf318f-bcfc-4309-97d0-76c2e7c96a7e; userInfo=admin@cz.com:admin; JSESSIONID=EE64079137ABCE9E0DB5C0F6BF2F4994");
        CloseableHttpResponse httpResponse = null;
        try
        {
            // 请求并获得响应结果
            httpResponse = httpClient.execute(httpGet);
            HttpEntity httpEntity = httpResponse.getEntity();
            // 输出请求结果
            System.out.println(EntityUtils.toString(httpEntity));
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

        // 无论如何必须关闭连接
        finally
        {
            if (httpResponse != null)
            {
                try
                {
                    httpResponse.close();
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }

            if (httpClient != null)
            {
                try
                {
                    httpClient.close();
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
        }
    }
}
