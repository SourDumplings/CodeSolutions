package com.itheima.servlet;

import java.io.IOException;
import java.util.Iterator;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
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
		// Cookie的简单使用
		
		// Cookie是服务器发送给客户端并且保存在客户端上的一份小数据
		
		response.setContentType("text/html;charset=UTF-8");
		
		/*
		 * 方法参数要什么就给什么，对象
		 * 
		 * 创建对象的方法：
		 * 
		 * 1.直接new
		 * 
		 * 2.单例模式 | 提供静态方法
		 * 
		 * 3.工厂模式构建 stu
		 * 	StuFactory StuBuilder
		 * 
		 * 
		 */
		
		// 发送Cookie给客户端
		Cookie cookie = new Cookie("aa", "bb");
		// 给响应添加一个Cookie
		response.addCookie(cookie);
		response.getWriter().write("请求成功了...");
		
		
		// 获取客户端带过来的Cookie（也可以写前面）
		Cookie[] cookies = request.getCookies();
		if (cookies != null)
		{
			for (Cookie c : cookies)
			{
				String cookieName = c.getName();
				String cookieValue = c.getValue();
				System.out.println("cookieName: " + cookieName +
						", cookieValue: " + cookieValue);
			}
		}
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
