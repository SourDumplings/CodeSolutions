package com.itheima.spring.demo1;

/**   
 * @ClassName  UserServiceImpl   
 * @Description TODO(用户管理业务层实现类)   
 * @author SourDumplings
 * @date   2019年9月21日 下午9:54:13   
 *     
 * @PL https://github.com/SourDumplings
 */ 
public class UserDaoImpl implements UserDao
{
	private String name;
	
	
	
	public String getName()
	{
		return name;
	}



	public void setName(String name)
	{
		this.name = name;
	}



	public void save()
	{
		// TODO Auto-generated method stub
		System.out.println("UserDao实现类执行了..., name = " + name);
	}

}
