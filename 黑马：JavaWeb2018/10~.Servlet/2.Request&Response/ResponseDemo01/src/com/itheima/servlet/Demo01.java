package com.itheima.servlet;

import java.io.IOException;
import java.nio.charset.Charset;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Demo01
 */
public class Demo01 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		// test01(response);

		// 响应的数据中有中文，有可能出现中文乱码

		// 字符流的形式输出
		// test03(response);

		// 字节流形式输出
		/*
		 * 如果想让服务器端出去的中文，在客户端能够正常显示，只要保证： 出去用的编码和客户端看的编码是一样的即可
		 * 
		 * 默认情况下getOutputStream()输出使用的是UTF-8的编码，如果想指定具体的编码，可以在获取Byte数组的时候，指定编码
		 */
		
		// 设置响应的数据类型是html文本，并且告知浏览器使用的是UTF-8编码
		response.setContentType("text/html;charset=GBK"); 
		
		// String这个类里面getByte方法使用的码表默认是UTF-8，跟tomcat使用的码表没有关系，tomcat默认使用的是iso-8859-1
		String csn = Charset.defaultCharset().name();
		System.out.println("默认的String的getByte方法使用的码表是：" + csn);
		
		// 1.指定浏览器看这份数据用的码表
//		response.setHeader("Content-Type", "text/html; charset=UTF-8");
		
		// 2.指定输出的中文用的码表
//		response.getOutputStream().write("我爱深圳黑马程序员...".getBytes());
//		response.getOutputStream().write("我爱深圳黑马程序员...".getBytes("UTF-8"));
		 response.getOutputStream().write("我爱深圳黑马程序员...".getBytes("GBK"));
		
		 
		
	}

	private void test03(HttpServletResponse response) throws IOException
	{
		// 这里写出的文字默认的编码是ISO-8859-1，我们可以指定写出去的时候用什么编码写
		// 1.指定输出到客户端的时候，使用的文字为UTF-8编码
		response.setCharacterEncoding("UTF-8");

		// 2.直接规定浏览器看这份数据的时候使用什么数据来看
		response.setHeader("Content-Type", "text/html; charset=UTF-8");

		response.getWriter().write("我爱黑马训练营...");
	}

	private void test01(HttpServletResponse response) throws IOException
	{
		// 以字符流的方式写数据
		// response.getWriter().write("<h1>hello response...</h1>");
		// 以字节流的方式写数据
		response.getOutputStream().write("<h1>hello response...2222</h1>".getBytes());

		// 设置这个请求的处理状态码
		// response.setStatus(arg0);
		// 设置一个头
		// response.setHeader(arg0, arg1);

		// 设置响应内容类型以及编码
		// response.setContentType(arg0);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
