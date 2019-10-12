package com.itheima.commoncrud;

import java.sql.Connection;
import java.sql.ParameterMetaData;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import org.junit.Test;

import com.itheima.domain.Account;
import com.itheima.util.JDBCUtil2;

public class CommonCRUDUtil
{
	@Test
	public void testQuery()
	{
		Account query = query("select * from account where id = ?", new ResultSetHandler()
		{
			@Override
			public Account handle(ResultSet rs)
			{
				// TODO Auto-generated method stub
				try
				{
					Account account = null;
					if (rs.next())
					{
						String name = rs.getString("name");
						int money = rs.getInt("money");
						
						account = new Account();
						account.setMoney(money);
						account.setName(name);
					}
					return account;
				}
				catch (SQLException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				return null;
			}
		}, 3);
		
		System.out.println(query.toString());
	}
	
	public <T> T query(String sql, ResultSetHandler handler, Object ...args)
	{
		Connection conn = null;
		PreparedStatement ps = null;
		T t = null;
		
		try
		{
			conn = JDBCUtil2.getConnection();
			ps = conn.prepareStatement(sql);
			
			// 因为不知道是什么类型的数据，所以都使用setObject来对待
			ParameterMetaData metaData = ps.getParameterMetaData();
			int parameterCount = metaData.getParameterCount();
			for (int i = 0; i < parameterCount; i++)
			{
				ps.setObject(i+1, args[i]);
			}
			
			// 执行查询工作，得到结果集
			ResultSet rs = ps.executeQuery();
			
			// 把结果集丢给调用者，让他去封装数据，返回封装数据
			t = handler.handle(rs);
			return t;
			
/*			// 问题1：这里的数据获取，以及封装成什么对象返回，不知道。因为调用的地方需要的数据不同。
			// 
			while (rs.next())
			{
				rs.getInt("id");
				rs.getInt("name");
			}*/
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
		finally
		{
			JDBCUtil2.release(conn, null, ps);
		}
		return null;
	}
	
	@Test
	public void testUpdate()
	{
//		update("insert into account values(null, ?, ?)", "aa", 10);
//		update("delete from account where id = ?", 11);
//		update("update account set money = ? where id = ?", 99, 8);
		
		
//		update("update account set money = ? where id = ?", 999, 8, 10, 11, 12);
		update02("update account set money = ? where id = ?", 999, 8, 10, 11, 12);
	}
	
	
	/**
	 * @throws SQLException    
	 * @Title: update   
	 * @Description: TODO(应付通用的增删改功能)   
	 * @param: sql需要操作的sql语句，args有几个?占位符就传几个参数进来，以参数个数为准      
	 * @return: void      
	 * @throws   
	 */  
	public void update(String sql, Object... args)
	{
		Connection conn = null;
		PreparedStatement ps = null;
		try
		{
			conn = JDBCUtil2.getConnection();
			ps = conn.prepareStatement(sql);
			
			// 因为不知道是什么类型的数据，所以都使用setObject来对待
			for (int i = 0; i < args.length; i++)
			{
				ps.setObject(i+1, args[i]);
			}
			
			ps.executeUpdate();
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil2.release(conn, null, ps);
		}
	}
	
	
	/**
	 * @throws SQLException    
	 * @Title: update02   
	 * @Description: TODO(应付通用的增删改功能)   
	 * @param: sql需要操作的sql语句，args有几个?占位符就传几个参数进来，以?个数为准      
	 * @return: void      
	 * @throws   
	 */  
	public void update02(String sql, Object... args)
	{
		Connection conn = null;
		PreparedStatement ps = null;
		try
		{
			conn = JDBCUtil2.getConnection();
			ps = conn.prepareStatement(sql);
			
			// 因为不知道是什么类型的数据，所以都使用setObject来对待
			ParameterMetaData metaData = ps.getParameterMetaData();
			int parameterCount = metaData.getParameterCount();
			for (int i = 0; i < parameterCount; i++)
			{
				ps.setObject(i+1, args[i]);
			}
			
			
			ps.executeUpdate();
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil2.release(conn, null, ps);
		}
		
		
	}
}
