package a.b.c01;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.ServletInputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import org.apache.commons.io.IOUtils;

/**
 * Servlet implementation class ServletDemo01
 */
public class ServletDemo01 extends HttpServlet
{
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub

		// // 这个API拿不到数据，会得到null
		// // 因为这种方式只能获得请求体键值对或者url后面键值对的数据
		// request.getParameter("username");
		// request.getParameter("password");
		// request.getParameter("userhead");

		// // 通过request获得到一个输入流对象
		// ServletInputStream is = request.getInputStream();
		// // 打印输入流对象中的内容
		// int i = is.read();
		// while (i != -1)
		// {
		// char c = (char) i;
		// System.out.print(c);
		// i = is.read();
		// }

		/*
		 * 思路:
		 * 
		 * 1_导入commons-fileupload-1.2.1.rar之后
		 * 
		 * 2_执行很简单的3行语句,
		 * 
		 * 3_获取到一个集合(<FileItem>对象)
		 * 
		 * 将每对分割线中间的内容封装在FileItem对象上.
		 * 
		 * 4_遍历集合
		 * 
		 * 5_如果当前的FileItem对象是普通项
		 * 
		 * 将普通项上name属性的值作为键,将获取到的内容作为值,放入MAP中
		 * 
		 * {username<==>tom,password<==>1234}
		 * 
		 * 6_如果当前的FileItem对象是上传项
		 * 
		 * 通过FileItem获取到输入流对象,通过输入流可以获取到图片二进制数据
		 * 
		 * 在服务端创建一个空文件(后缀必须和上传到服务端的文件名后缀一致)
		 * 
		 * 建立和空文件对应的输出流
		 * 
		 * 将输入流中的数据刷到输出流中
		 * 
		 * 释放资源
		 * 
		 * 向map中存入一个键值对的数据 userhead<===> /image/11.bmp
		 * 
		 * {username<==>tom,password<==>1234,userhead<===>image/11.bmp}
		 * 
		 * 7_利用BeanUtils将MAP中的数据填充到user对象上
		 * 
		 * 8_调用servcie_dao将user上携带的数据存入数据仓库,重定向到查询全部商品信息路径
		 */

		// Map目的：携带数据{username<==>tom, password<==>1234,
		// userhead<==>/images/11.bmp}
		Map<String, String> map = new HashMap<String, String>();
		User user = new User();
		try
		{
			// 以下三行代码：通过request.getInputStream();获取请求体的全部内容
			// 进行解析，将没对分割线中的内容封装在了FileItem对象中
			DiskFileItemFactory fac = new DiskFileItemFactory();
			ServletFileUpload upload = new ServletFileUpload(fac);
			List<FileItem> list = upload.parseRequest(request);

			// 遍历集合
			for (FileItem item : list)
			{
				if (item.isFormField())
				{
					// 普通项
					/*
					 * System.out.println(item.getFieldName() + "。。。。。普通项");
					 * System.out.println(item.getName() + "。。。。。普通项");
					 * System.out.println(item.getString() + "。。。。。普通项");
					 */
					map.put(item.getFieldName(), item.getString("utf-8"));
				}
				else
				{
					// 上传项
					/*
					 * System.out.println(item.getFieldName() + "。。。。。上传项");
					 * System.out.println(item.getName() + "。。。。。上传项");
					 * System.out.println(item.getString() + "。。。。。上传项"); //
					 * 不推荐用此api获取图片二进制数据
					 */
					InputStream is = item.getInputStream();
					// 建立空文件
					// D:\apache-tomcat-7.0.52\webapps\TestUpload\images\img
					String realPath = getServletContext().getRealPath("/images/img/");
					File file = new File(realPath, item.getName());
					if (!file.exists())
					{
						file.createNewFile();
					}
					// 建立和空文件对应的输出流
					OutputStream os = new FileOutputStream(file);
					// 释放资源：流对接，利用IO这个API
					IOUtils.copy(is, os);
					IOUtils.closeQuietly(is);
					IOUtils.closeQuietly(os);
					// 向map中存入一个键值数据
					map.put("userhead", "/images/img/" + item.getName());
				}
			}
			// 利用BeanUtils将数据放在User对象上面
			BeanUtils.populate(user, map);
			System.out.println(user);
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
