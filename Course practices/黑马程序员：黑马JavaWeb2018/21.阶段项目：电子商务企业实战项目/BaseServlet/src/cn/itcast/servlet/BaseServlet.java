package cn.itcast.servlet;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class BaseServlet
 */
public class BaseServlet extends HttpServlet
{
	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		// TODO Auto-generated method stub
		// 获取客户端提交到服务端的method的对应值
		String md = request.getParameter("method");
		// 通过判断md的内容来决定本次功能

		// 存放功能执行完毕后需要转发到的路径
		String path = null;
		
		// 获取到当前的字节码对象（ServletDemo02.class在内存中的对象）
		Class claz = this.getClass();
		// 获取clazz名称为md方法
		try
		{
			Method method = claz.getMethod(md, HttpServletRequest.class, HttpServletResponse.class);
		
			if (method != null)
			{
				path = (String) method.invoke(this, request, response);
			}

			if (path != null)
			{
				// 服务端转发
				request.getRequestDispatcher(path).forward(request, response);
			}
		}
		catch (NoSuchMethodException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (SecurityException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IllegalAccessException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IllegalArgumentException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (InvocationTargetException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
