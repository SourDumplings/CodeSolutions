package com.itheima.servlet;

import java.io.IOException;
import java.util.Enumeration;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class HelloServletConfig
 */
public class HelloServletConfig extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		// ServletConfig可以获得Servlet在配置时的一些信息
		ServletConfig servletConfig = getServletConfig();
		// 获取Servlet里面servlet-name中的文本
		String servletName = servletConfig.getServletName();
		System.out.println("servletName = " + servletName);
		
		// 可以获取具体的某一个参数
		String initParameter = servletConfig.getInitParameter("address");
		System.out.println("initParameter = " + initParameter);
		
		System.out.println("------------------");
		// 获取所有的参数名称
		Enumeration<String> names = servletConfig.getInitParameterNames();
		while (names.hasMoreElements())
		{
			String name = names.nextElement();
			String value = servletConfig.getInitParameter(name);
			System.out.println("name === " + name + ", value === " + value);
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO 来了doPost请求让它去执行doGet方法
		doGet(request, response);
	}

}
