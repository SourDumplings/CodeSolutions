package com.itheima.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Demo02
 */
public class Demo02 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub

		// 去客户端发送过来的Cookie
		Cookie[] cookies = request.getCookies();
		if (cookies != null)
		{
			for (Cookie c : cookies)
			{
				System.out.println(c.getName() + ":" + c.getValue());
			}
		}

		// 1.先写Cookie，可以给客户端返回多个Cookie
		Cookie cookie = new Cookie("name", "zhangsan");

		// 2.这个Cookie的有效期。默认情况下，
		// 关闭浏览器后，cookie就没有。对此可以设置Cookie有效期。
		// 正值表示在这个数字的秒数过后，Cookie会失效，负值表示关闭浏览器就失效，默认-1
		cookie.setMaxAge(60 * 60); // 设置name这个Cookie的有效期为1hour

		// 赋值新的值
		// cookie.setValue(newValue);

		// 用于指定只有请求了指定的域名才会带上该Cookie
		// cookie.setDomain(".itheima.com");
		// 只有访问该域名下的CookieDemo这个路径地址才会带上该Cookie
		// cookie.setPath("/CookieDemo");
		// 即www.itheima.com/CookieDemo/... 才会带

		response.addCookie(cookie);

		Cookie cookie2 = new Cookie("age", "18");
		response.addCookie(cookie2);

		response.getWriter().write("hello cookie...");

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
