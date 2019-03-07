package com.itheima.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.itheima.dao.UserDao;
import com.itheima.dao.impl.UserDaoImpl;
import com.itheima.domain.UserBean;

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
		try
		{
			String username = request.getParameter("username");
			String password = request.getParameter("password");
			String auto_login = request.getParameter("auto_login");
			
			UserBean user = new UserBean();
			user.setUsername(username);
			user.setPassword(password);
			
			System.out.println("username: " + username + ", password: " + password);
			
			UserDao dao = new UserDaoImpl();
			UserBean userBean = dao.login(user);
			
			if (userBean != null)
			{
				if (auto_login != null && auto_login.equals("on"))
				{
					// 页面提交上来的时候，是否选择了自动登录
					Cookie cookie = new Cookie("auto_login", username + "#itheima#" + password);
					cookie.setMaxAge(60 * 60 * 24 * 7); // 7day有效期
					response.addCookie(cookie);
					cookie.setPath(request.getContextPath()); // 等价于下一行
					cookie.setPath("/AutoLoginDemo");
				}
				// 登录成功，进入首页
				request.getSession().setAttribute("userBean", userBean);
				response.sendRedirect("index.jsp");
			}
			else
			{
				request.getRequestDispatcher("login.html").forward(request, response);
			}
			
		}
		catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
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
