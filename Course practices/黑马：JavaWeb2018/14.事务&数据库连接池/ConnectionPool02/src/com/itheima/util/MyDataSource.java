package com.itheima.util;

import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.SQLFeatureNotSupportedException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Logger;

import javax.sql.DataSource;

/**   
 * @ClassName:  MyDataSource   
 * @Description:TODO(这是一个数据库连接池，一开始先往池子里放10个连接，
 * 来的程序通过getConnection获取连接，用完之后用addBack归还连接，以及扩容)   
 * @author: SourDumplings
 * @date:   2019年2月28日 上午9:48:50   
 *     
 * @link: https://github.com/SourDumplings
 *
 *
 * 问题：
 *
 * 1.需要额外记住addBack方法
 * 
 * 2.单例
 * 
 * 3.无法面向接口编程(由于多了个addBack,接口中没有定义)
 *	面向接口编程例子：
 *		UserDao dao = new UserDaoImpl();
 *		dao.insert();
 *
 */ 
public class MyDataSource implements DataSource
{
	List<Connection> list = new ArrayList<Connection>();
	
	public MyDataSource()
	{
		// TODO Auto-generated constructor stub
		for (int i = 0; i < 10; i++)
		{
			Connection conn = JDBCUtil.getConnection();
			list.add(conn);
		}
	}
	
	
	// 该连接池对外公布的获取连接的方法
	@Override
	public Connection getConnection() throws SQLException
	{
		// TODO Auto-generated method stub
		if (list.size() == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				Connection conn = JDBCUtil.getConnection();
				list.add(conn);
			}
		}
		// remove(0)移除第一个
		Connection conn = list.remove(0);
		
		// 再把这个对象抛出去的时候，对这个对象进行包装
		Connection connection = new ConnectionWrap(conn, list);
		
		return connection;
	}
	
	// 用完之后记得归还
	public void addBack(Connection conn)
	{
		list.add(conn);
		return;
	}
	
	// --------------------------------------------

	@Override
	public PrintWriter getLogWriter() throws SQLException
	{
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void setLogWriter(PrintWriter out) throws SQLException
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setLoginTimeout(int seconds) throws SQLException
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public int getLoginTimeout() throws SQLException
	{
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public Logger getParentLogger() throws SQLFeatureNotSupportedException
	{
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <T> T unwrap(Class<T> iface) throws SQLException
	{
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean isWrapperFor(Class<?> iface) throws SQLException
	{
		// TODO Auto-generated method stub
		return false;
	}
	

	@Override
	public Connection getConnection(String username, String password) throws SQLException
	{
		// TODO Auto-generated method stub
		return null;
	}

}
