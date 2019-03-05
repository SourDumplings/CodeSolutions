package com.itheima.servlet;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.itheima.dao.CityDao;
import com.itheima.dao.impl.CityDaoImpl;
import com.itheima.domain.CityBean;
import com.thoughtworks.xstream.XStream;

/**
 * Servlet implementation class CityServlet
 */
public class CityServlet extends HttpServlet
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
			// 1.获取参数
			int pid = Integer.parseInt(request.getParameter("pid"));
			// 2.找出所有的城市
			CityDao dao = new CityDaoImpl();
			List<CityBean> list = dao.findCity(pid);
			// 3.返回数据 手动拼太麻烦 ---> XStream
			XStream xStream = new XStream();
			// 想把cid做成属性
			// xStream.useAttributeFor(CityBean.class, "cid");

			// 设置别名
			xStream.alias("city", CityBean.class);
			// 把xml转成一个JavaBean对象
			String xml = xStream.toXML(list);
//			System.out.println(xml);
			
			response.setContentType("text/xml;charset=UTF-8");
			response.getWriter().write(xml);

		}
		catch (NumberFormatException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
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
