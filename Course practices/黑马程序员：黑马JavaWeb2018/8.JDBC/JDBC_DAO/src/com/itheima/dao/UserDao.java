package com.itheima.dao;

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
	public void insert(String username, String password);
	
	public void delete(int id);
	
	// 根据ID更新用户名
	public void update(int id, String username);
	
	/**   
	 * @Title: findAll   
	 * @Description: TODO(查询所有)   
	 * @param:       
	 * @return: void      
	 * @throws   
	 */  
	public void findAll();
	
	public void login(String username, String password);
}
