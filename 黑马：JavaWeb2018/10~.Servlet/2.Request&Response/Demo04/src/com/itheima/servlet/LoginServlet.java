package com.itheima.servlet;

import java.io.IOException;
import java.io.PrintWriter;

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
	 * request就是获取包含请求的信息
	 * response就是响应给浏览器的信息
	 * 
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		// 1.获取数据
		String userName = request.getParameter("username");
		String passWord = request.getParameter("password");

		System.out.println("username = " + userName + ", password = " + passWord);
		// 2.校验数据
		PrintWriter pw = response.getWriter();
		if (userName.equals("admin") && passWord.equals("123"))
		{
			// System.out.println("登陆成功");
//			pw.write("login success");
			
			// 成功就跳转到login_success.html
			
			// 1.登陆成功次数累加
			// 获取以前存的值，然后在此基础上+1
			Object obj = getServletContext().getAttribute("count");
			int totalCount = 0;
			if (obj != null)
			{
				totalCount = (Integer) obj;
			}
			System.out.println("已知登录成功的次数是：" + (totalCount + 1));
			// 给count赋予新值
			getServletContext().setAttribute("count", totalCount + 1);
			
			// 2.跳转到成功页面
			// 设置状态码？重新定位 状态码
			response.setStatus(302);
			// 定位跳转的位置是哪一个页面
			response.setHeader("Location", "login_success.html");
		}
		else
		{
			// System.out.println("登录失败");
			pw.write("login fail");
		}

		//
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
