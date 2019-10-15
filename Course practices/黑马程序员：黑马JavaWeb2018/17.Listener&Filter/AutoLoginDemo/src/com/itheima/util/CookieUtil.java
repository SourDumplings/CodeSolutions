package com.itheima.util;

import javax.servlet.http.Cookie;

public class CookieUtil
{
	public static Cookie findCookie(Cookie[] cookies, String name)
	{
		for (Cookie cookie : cookies)
		{
			if (name.equals(cookie.getName()))
			{
				return cookie;
			}
		}
		return null;
	}
}
