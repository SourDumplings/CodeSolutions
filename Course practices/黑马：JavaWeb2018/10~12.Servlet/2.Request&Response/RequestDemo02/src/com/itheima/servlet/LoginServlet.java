package com.itheima.servlet;

import java.io.IOException;
import java.io.UnsupportedEncodingException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class LoginServlet
 */
public class LoginServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		
		// 这个设置的是请求体中文字的编码，get方法是没用的。
		// 这一行设置一定要在拿数据之前
		request.setCharacterEncoding("utf-8");
		
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		
//		test01(username, password);
		
		// post过来的数据乱码处理
		System.out.println("--------post------------");
		System.out.println("username: " + username);
		System.out.println("password: " + password);
	}

	/**   
	 * @Title: test01   
	 * @Description: TODO(处理get请求过来的数据乱码)   
	 * @param: @param username
	 * @param: @param password
	 * @param: @throws UnsupportedEncodingException      
	 * @return: void      
	 * @throws   
	 */  
	private void test01(String username, String password) throws UnsupportedEncodingException
	{
		System.out.println("username: " + username);
		// get请求过来的数据在url地址栏上就已经经过编码了，所以我们取到的就是乱码
		// tomcat收到了这批数据，getParaimeter默认使用ISO-8859-1去解码（可改）
		// 先让文字回到ISO-8859-1对应的字节数组，再按UTF-8组拼字符串
		username = new String(username.getBytes("ISO-8859-1"), "UTF-8");
		
		System.out.println("username: " + username);
		System.out.println("password: " + password);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		System.out.println("来了一个post请求...");
		doGet(request, response);
	}

}
