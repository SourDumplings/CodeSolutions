package cn.itcast.test00;

import java.io.IOException;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;

/**
 * Servlet Filter implementation class EncodingFilter
 */
public class EncodingFilter implements Filter
{

	/**
	 * @see Filter#destroy()
	 */
	public void destroy()
	{
		// TODO Auto-generated method stub
	}

	/**
	 * @see Filter#doFilter(ServletRequest, ServletResponse, FilterChain)
	 */
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException
	{
		// TODO Auto-generated method stub
		// place your code here
		// 将request这个对象转换为HttpServletRequest
		final HttpServletRequest req = (HttpServletRequest) request;
		// 让JDK在内存中生成代理对象，增强req对象上的getParameter(name).API
		HttpServletRequest myReq = (HttpServletRequest) Proxy.newProxyInstance(EncodingFilter.class.getClassLoader(),
				req.getClass().getInterfaces(), new InvocationHandler()
				{

					public Object invoke(Object proxy, Method method, Object[] args) throws Throwable
					{
						Object obj = null;

						// TODO Auto-generated method stub
						if (method.getName().equalsIgnoreCase("getParameter"))
						{
							// 获取本次请求的方式
							String md = req.getMethod();
							if (md.equalsIgnoreCase("get"))
							{
								// get方式的请求
								// 调用req对象上的getParameter方法
								String v = (String) method.invoke(req, args);
								// 转码
								String vRes = new String(v.getBytes("ISO-8859-1"), "UTF-8");
								return vRes;
							}
							else
							{
								// post方式的请求
								req.setCharacterEncoding("UTF-8");
								obj = method.invoke(req, args);
							}
						}
						else
						{
							obj = method.invoke(req, args);
						}

						return obj;
					}
				});
		// 打印代理对象的哈希吗
		System.out.println("myReq.hashCode():" + myReq.hashCode());

		// pass the request along the filter chain
		// 将代理对象放行
		chain.doFilter(myReq, response);
	}

	/**
	 * @see Filter#init(FilterConfig)
	 */
	public void init(FilterConfig fConfig) throws ServletException
	{
		// TODO Auto-generated method stub
	}

}
