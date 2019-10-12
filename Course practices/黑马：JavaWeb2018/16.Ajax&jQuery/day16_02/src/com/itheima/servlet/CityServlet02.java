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

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

/**
 * Servlet implementation class CityServlet
 */
public class CityServlet02 extends HttpServlet
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
			// 3.返回数据 list集合->json数据
			/*
			 * JSONObject ---> 变成简单数据 JSONArray ---> 变成数组
			 */
			JSONArray jsonArray = JSONArray.fromObject(list);
			String jString = jsonArray.toString();
			
//			System.out.println(jString);
			response.setContentType("text/html;charset=UTF-8"); 
			response.getWriter().write(jString);

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
