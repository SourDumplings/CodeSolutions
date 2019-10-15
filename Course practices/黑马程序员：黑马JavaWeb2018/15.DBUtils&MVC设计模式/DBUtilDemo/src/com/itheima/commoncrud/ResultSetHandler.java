package com.itheima.commoncrud;

import java.sql.ResultSet;

public interface ResultSetHandler
{
	/**   
	 * @Title: handle   
	 * @Description: TODO(这里用一句话描述这个方法的作用)   
	 * @param: @param rs      
	 * @return: void      
	 * @throws   
	 */  
	public <T> T handle(ResultSet rs);
}
