package com.itheima.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ClearHistory
 */
/**   
 * @ClassName:  ClearHistory   
 * @Description:TODO(清除Cookie)   
 * @author: SourDumplings
 * @date:   2019年2月22日 下午2:28:46   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public class ClearHistory extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		Cookie cookie = new Cookie("history", "");
		cookie.setMaxAge(0); // 设置立即删除
		cookie.setPath("/CookieDemo02");
		response.addCookie(cookie);
		
		response.sendRedirect("product_list.jsp");
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
