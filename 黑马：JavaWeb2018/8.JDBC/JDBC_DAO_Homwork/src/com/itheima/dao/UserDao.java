package com.itheima.dao;

import java.util.List;

/**   
 * @ClassName:  UserDao   
 * @Description:TODO(声明操作数据库的方法)   
 * @author: SourDumplings
 * @date:   2019年2月2日 下午8:30:27   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public interface UserDao
{
	public int insert(String username, String password);
	
	public int delete(int id);
	
	// 根据ID更新用户名
	public int update(int id, String username);
	
	/**   
	 * @Title: findAll   
	 * @Description: TODO(查询所有)   
	 * @param:       
	 * @return: void      
	 * @throws   
	 */  
	public List<User> findAll();
	
	public User login(String username, String password);
}
