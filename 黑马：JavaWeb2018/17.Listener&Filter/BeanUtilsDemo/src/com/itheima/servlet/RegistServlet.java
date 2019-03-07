package com.itheima.servlet;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.sql.Date;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.beanutils.ConvertUtils;

import com.itheima.domain.UserBean;
import com.itheima.util.MyDateConverter;

/**
 * Servlet implementation class RegistServlet
 */
public class RegistServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8"); // 只针对POST有效
		
		// 使用BeanUtils
		try
		{
			// 注册自己的转换器
			ConvertUtils.register(new MyDateConverter(), Date.class);
			
			UserBean bean = new UserBean();
			Map<String, String[]> map = request.getParameterMap();
			
			BeanUtils.populate(bean, map);
			
			System.out.println(bean);
		}
		catch (IllegalAccessException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (InvocationTargetException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
/*		
 * 		使用传统方法
 * 		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String email = request.getParameter("email");
		String phone = request.getParameter("phone");
		String address = request.getParameter("address");
		
		bean.setUsername(username);
		bean.setPassword(password);
		bean.setEmail(email);
		bean.setPhone(phone);
		bean.setAddress(address);
		
		System.out.println(bean);*/
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
