package com.itheima.servlet;

import java.io.UnsupportedEncodingException;

import sun.misc.BASE64Encoder;

public class DownLoadUtil
{
	public static String base64EncodeFileName(String fileName)
	{
		BASE64Encoder base64Encoder = new BASE64Encoder();
		try
		{
			return "=?UTF-8?B?" + new String(base64Encoder.encode(fileName.getBytes("UTF-8"))) + "?=";
		}
		catch (UnsupportedEncodingException e)
		{
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}
}
