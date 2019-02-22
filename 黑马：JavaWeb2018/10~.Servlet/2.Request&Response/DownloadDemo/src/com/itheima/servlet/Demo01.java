package com.itheima.servlet;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLEncoder;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Demo01
 */
public class Demo01 extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		// 1.获取要下载的文件名字 aa.jpg --> 变成流
		String fileName = request.getParameter("filename");
		
		// 来一个get请求，这个file里面有中文
		fileName = new String(fileName.getBytes("ISO-8859-1"), "UTF-8");
		System.out.println("fileName = " + fileName);
		
		// 2.获取这个文件在tomcat中的绝对路径地址
		String path = getServletContext().getRealPath("download/" + fileName);
		
		/*
		 * 如果文件的名字带有中文，那么需要对这个文件名进行编码处理
		 * 
		 * IE、Chrome，使用URLEncoding编码
		 * Firefox使用Base64编码
		 *
		 */
		
		String clientType = request.getHeader("User-Agent");
		
		// 对中文名字进行编码处理
		if (clientType.contains("Firefox"))
		{
			// 火狐浏览器
			DownLoadUtil.base64EncodeFileName(fileName);
		}
		else
		{
			// 谷歌或者IE
			fileName = URLEncoder.encode(fileName, "UTF-8");
		}
		
		
		
		// 让浏览器收到这份资源的时候以下载的方式提醒用户，而不是直接展示
		response.setHeader("Content-Disposition", "attachment; filename=" + fileName); 
		
		// 3.转换成输入流
		InputStream is = new FileInputStream(path);
		ServletOutputStream os = response.getOutputStream();
		
		int len = 0;
		byte[] buffer = new byte[1024];
		while ((len = is.read(buffer)) != -1)
		{
			os.write(buffer, 0, len);
		}
		
		os.close();
		is.close();
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
