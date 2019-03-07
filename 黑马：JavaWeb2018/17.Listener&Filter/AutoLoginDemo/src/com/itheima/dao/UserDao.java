package com.itheima.dao;

import java.sql.SQLException;

import com.itheima.domain.UserBean;

public interface UserDao
{
	/**   
	 * @Title: login   
	 * @Description: TODO(执行登录，并返回用户的所有信息)   
	 * @param: @param user
	 * @param: @return
	 * @param: @throws SQLException      
	 * @return: UserBean      
	 * @throws   
	 */  
	UserBean login(UserBean user) throws SQLException;
}
