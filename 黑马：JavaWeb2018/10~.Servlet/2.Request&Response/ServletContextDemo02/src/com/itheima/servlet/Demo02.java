package com.itheima.servlet;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Demo02
 */
public class Demo02 extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		// 1.创建属性对象
		Properties properties = new Properties();
		
		// 2.指定载入的数据源
		// 此处如果想获取Web工程下的资源，用普通的FileInputStream写法是不OK的
		// 因为路径不对了，由于我们是Web工程，并不像原先JavaSE中的相对路径是由JRE确定，
		// Web工程中JRE后面会由Tomcat管理，所以这里真正相对路径是Tomcat中的bin目录
		InputStream is = new FileInputStream("src/config.properties");
		properties.load(is);
		
		// 3.获取属性的值
		String name = properties.getProperty("name");
		
		System.out.println("name = " + name);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
