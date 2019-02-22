package com.itheima.servlet;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.itheima.util.CookieUtil;

/**
 * Servlet implementation class Demo03
 */
public class Demo03 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		response.setContentType("text/html;charset=UTF-8");
		
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		
		if (username.equals("admin") && password.equals("123"))
		{
			// 获取Cookie last
			Cookie[] cookies = request.getCookies();
			
			// 从数组中找出想要的Cookie
			Cookie cookie = CookieUtil.findCookie(cookies, "last");
			
			if (cookie == null)
			{
				// 第一次登录，没有Cookie
				Cookie c = new Cookie("last", System.currentTimeMillis() + "");
				c.setMaxAge(60 * 60); // 设置Cookie为一个小时
				response.addCookie(c);
				response.getWriter().write("欢迎您，" + username);
			}
			else
			{
				// 1.有Cookie
				long lastVisitTime = Long.parseLong(cookie.getValue());
				// 2.获取上次登录的时间
				response.getWriter().write("欢迎您，" + username +
						"。您上次来访时间是：" + new Date(lastVisitTime));
				// 3.重置登录时间
				cookie.setValue(System.currentTimeMillis() + "");
				response.addCookie(cookie);
			}
			
			
		}
		else
		{
			response.getWriter().write("登录失败");
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
