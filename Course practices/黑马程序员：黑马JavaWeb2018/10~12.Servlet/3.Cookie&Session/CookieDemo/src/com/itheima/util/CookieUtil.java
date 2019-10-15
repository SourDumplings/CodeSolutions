package com.itheima.util;

import javax.servlet.http.Cookie;

public class CookieUtil
{
	/**   
	 * @Title: findCookie   
	 * @Description: TODO(从一个Cookie数组中找到我们想要的具体的Cookie对象)   
	 * @param: @param cookies
	 * @param: @param name
	 * @param: @return      
	 * @return: Cookie      
	 * @throws   
	 */  
	public static Cookie findCookie(Cookie[] cookies, String name)
	{
		if (cookies != null)
		{
			for (Cookie cookie : cookies)
			{
				if (name.equals(cookie.getName()))
				{
					return cookie;
				}
			}
		}
		
		return null;
	}
}
