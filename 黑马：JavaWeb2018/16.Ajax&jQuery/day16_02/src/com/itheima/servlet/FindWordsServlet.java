package com.itheima.servlet;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.itheima.dao.WordsDao;
import com.itheima.dao.impl.WordsDaoImpl;
import com.itheima.domain.WordBean;

/**
 * Servlet implementation class FindWordsServlet
 */
public class FindWordsServlet extends HttpServlet
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
			// 1.先获取参数
			String word = request.getParameter("word");
			// System.out.println("word:" + word);

			// 2.让dao执行查询
			WordsDao dao = new WordsDaoImpl();
			List<WordBean> list = dao.findWords(word);

			// 3.返回数据
			// response.setContentType("text/html;charset=UTF-8");
			// response.getWriter().write("给你一份数据");
			request.setAttribute("list", list);
			request.getRequestDispatcher("list.jsp").forward(request, response);
		}
		catch (SQLException e)
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
