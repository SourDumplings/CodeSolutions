package com.itheima.util;

public class TextUtil
{
	/**   
	 * @Title: isEmpty   
	 * @Description: TODO(判断某一个字符串是否为空)   
	 * @param: @param s
	 * @param: @return      
	 * @return: boolean      
	 * @throws   
	 */  
	static public boolean isEmpty(CharSequence s)
	{
		return s == null || s.length() == 0;
	}
}
