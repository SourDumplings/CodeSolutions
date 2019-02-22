package com.itheima.servlet;

import java.io.IOException;
import java.util.LinkedHashMap;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class CarServlet
 */
public class CartServlet extends HttpServlet
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
		
		// 1.获取要添加到购物车的商品
		int id = Integer.parseInt(request.getParameter("id"));
		String[] names = {"Iphone7", "小米6", "三星Note8", "魅族7", "华为9"};
		String name = names[id];
		
		// 2.获取购物车存放东西的Session Map<String, Integer> inphone7 3
		Map<String, Integer> map = (Map<String, Integer>) request.getSession().getAttribute("cart");
		// Session没有存任何东西
		if (map == null)
		{
			// 把一个Map对象存放在Session里面去，并且保证只存一次
			map = new LinkedHashMap<String, Integer>();
			request.getSession().setAttribute("cart", map);
		}
		
		// 3.判断购物车里有没有该商品
		if (map.containsKey(name))
		{
			map.put(name, map.get(name) + 1);
		}
		else
		{
			map.put(name, 1);
		}
		
		// 4.输出界面
		response.getWriter().write("<a href='product_list.jsp'><h3>继续购物</h3></a>");
		response.getWriter().write("<a href='cart.jsp'><h3>去购物车结算</h3></a>");
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
