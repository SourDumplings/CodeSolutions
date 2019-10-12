package com.itheima.servlet;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Demo02
 */
public class Demo03 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub

		// text01();
//		text02();
		text03();
	}
	
	/**   
	 * @Title: text03   
	 * @Description: TODO(根据classloader去获取工程下的资源 类加载器)   
	 * @param: @throws FileNotFoundException
	 * @param: @throws IOException      
	 * @return: void      
	 * @throws   
	 */  
	private void text03() throws FileNotFoundException, IOException
	{
		// 获取ServletContext对象
		// 1.创建属性对象
		Properties properties = new Properties();
		
		/*
		 * ServletContext
		 * 
		 * 相对路径
		 * 
		 * ClassLoader
		 * a路径(默认的ClassLoader的路径)：
		 * 	D:\apache-tomcat-7.0.52\wtpwebapps\ServletContextDemo03\WEB-INF\classes
		 * b路径：
		 *  D:\apache-tomcat-7.0.52\wtpwebapps\ServletContextDemo03\file\config.properties
		 * 
		 * 必须要回到ServletContextDemo03这个目录下才能进入file目录
		 */
		
		
		// 获取该java文件的class，然后获取到加载这个class到虚拟机中的那个类加载器对象
		InputStream is = this.getClass().getClassLoader().getResourceAsStream("../../file/config.properties");
		properties.load(is);

		// 3.获取属性的值
		String name = properties.getProperty("name");

		System.out.println("name3 = " + name);
		is.close();
	}

	/**   
	 * @Title: text02   
	 * @Description: TODO(根据相对路径直接获取流对象)   
	 * @param: @throws FileNotFoundException
	 * @param: @throws IOException      
	 * @return: void      
	 * @throws   
	 */  
	private void text02() throws FileNotFoundException, IOException
	{
		// 获取ServletContext对象
		ServletContext context = getServletContext();

		// 1.创建属性对象
		Properties properties = new Properties();
		// 获取Web工程下的资源转化成流对象，直接使用了相对路径，前面隐藏着当前工程的根目录
		/*
		 * 相对路径（有参照物）
		 * 	相对的是工程在Tomcat中的根目录
		 * 
		 * a路径 -- 工程在Tomcat中的目录
		 * 	D:\apache-tomcat-7.0.52\wtpwebapps\ServletContextDemo03
		 * b路径
		 *  file/config.properties
		 * a和b拼起来就是绝对路径
		 * 
		 * 绝对路径（没有参照物）
		 * eg.D:\apache-tomcat-7.0.52\wtpwebapps\ServletContextDemo03\file\config.properties
		 */
		
		InputStream is = context.getResourceAsStream("file/config.properties");
		properties.load(is);

		// 3.获取属性的值
		String name = properties.getProperty("name");

		System.out.println("name2 = " + name);
		is.close();
	}

	/**   
	 * @Title: text01   
	 * @Description: TODO(先获取路径再获取流对象)   
	 * @param: @throws FileNotFoundException
	 * @param: @throws IOException      
	 * @return: void      
	 * @throws   
	 */  
	private void text01() throws FileNotFoundException, IOException
	{
		// 获取ServletContext对象
		ServletContext context = getServletContext();
		// 获取给定文件在Web服务器上的绝对路径
		String path = context.getRealPath("file/config.properties");

		// 1.创建属性对象
		Properties properties = new Properties();

		InputStream is = new FileInputStream(path);
		properties.load(is);

		// 3.获取属性的值
		String name = properties.getProperty("name");

		System.out.println("name = " + name);
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
