package com.itheima.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.itheima.util.CookieUtil;

/**
 * Servlet implementation class ProductInfoServlet
 */
public class ProductInfoServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		// 获取到当前用户准备浏览的商品ID
		String id = request.getParameter("id");

		Cookie[] cookies = request.getCookies();

		Cookie cookie = CookieUtil.findCookie(cookies, "history");

		// 第一次浏览
		if (cookie == null)
		{
			// 响应返回Cookie
			Cookie c = new Cookie("history", id);

			// 设置Cookie持续时间
			c.setMaxAge(60);

			// 设置只有访问这个工程的时候才带Cookie过来
			c.setPath("/CookieDemo02");

			response.addCookie(c);
		}
		else
		{
			// 1.获取以前的Cookie，因为以前的Cookie包含了浏览记录
			String ids = cookie.getValue();

			// 2.如果以前浏览过了，删除掉
			ids = ids.replace(id, "");
			ids = ids.replace("##", "#");

			// 3.让现在浏览的商品和以前浏览的商品形成新的Cookie值
			cookie.setValue(id + "#" + ids);
			
			// 设置Cookie持续时间
			cookie.setMaxAge(60);

			// 设置只有访问这个工程的时候才带Cookie过来
			cookie.setPath("/CookieDemo02");
			
			response.addCookie(cookie);

		}

		// 跳转具体的界面
		response.sendRedirect("product_info.htm");

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
