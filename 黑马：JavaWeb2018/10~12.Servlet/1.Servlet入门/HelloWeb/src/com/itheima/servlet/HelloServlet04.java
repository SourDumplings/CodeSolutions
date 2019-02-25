package com.itheima.servlet;

import java.io.IOException;

import javax.servlet.Servlet;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;

/**   
 * @ClassName:  HelloServlet03   
 * @Description:TODO(该Servlet用于演示Servlet的初始化时机提前)   
 * @author: SourDumplings
 * @date:   2019年2月15日 上午9:45:18   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public class HelloServlet04 implements Servlet
{

	public void init(ServletConfig config) throws ServletException
	{
		// TODO 在创建该Servlet的实例时就执行了该方法
		// 默认情况下是初次访问该Servlet才会创建实例，即一个Servlet只会初始化一次，init方法只会调用一次
		System.out.println("HelloServlet04初始化...");
	}

	public ServletConfig getServletConfig()
	{
		// TODO Auto-generated method stub
		return null;
	}

	/**   
	 * <p>Title: service</p>   
	 * <p>Description: 只要客户端来了一个请求，那么就执行这个方法了，该方法可以被执行很多次，一次请求对应一次service方法的调用</p>   
	 * @param req
	 * @param res
	 * @throws ServletException
	 * @throws IOException   
	 * @see javax.servlet.Servlet#service(javax.servlet.ServletRequest, javax.servlet.ServletResponse)   
	 */  
	public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		System.out.println("HelloServlet04.service方法调用了");
	}

	public String getServletInfo()
	{
		// TODO Auto-generated method stub
		return null;
	}

	/**   
	 * <p>Title: destroy</p>   
	 * <p>Description: 销毁的时候就会执行该方法：
	 * 		1.该项目从服务器tomcat中移除托管
	 * 		2.正常关闭服务器（运行shutdown.bat，而不是非正常关闭）
	 * </p>      
	 * @see javax.servlet.Servlet#destroy()   
	 */  
	public void destroy()
	{
		// TODO Auto-generated method stub
		System.out.println("HelloServlet04.destroy方法调用了");
	}
	
}