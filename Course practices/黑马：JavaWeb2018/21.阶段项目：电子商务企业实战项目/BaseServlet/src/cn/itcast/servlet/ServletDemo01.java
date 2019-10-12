package cn.itcast.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ServletDemo01
 */
public class ServletDemo01 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		// 获取客户端提交到服务端的method的对应值
		String md = request.getParameter("method");
		// 通过判断md的内容来决定本次功能

		// 存放功能执行完毕后需要转发到的路径
		String path = null;

		if (md.equals("addStu"))
		{
			path = addStu(request, response);
		}
		else if (md.equals("delStu"))
		{
			path = delStu(request, response);
		}
		else if (md.equals("checkStu"))
		{
			path = checkStu(request, response);
		}

		if (path != null)
		{
			// 服务端转发
			request.getRequestDispatcher(path).forward(request, response);
		}
	}

	protected String addStu(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
	{
		System.out.println("添加学生");
		return "/test.html";
	}

	protected String delStu(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
	{
		System.out.println("删除学生");
		return "/test.html";
	}

	protected String checkStu(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
	{
		System.out.println("检查学生");
		response.getWriter().println("DDDDDD");
		return null;
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
