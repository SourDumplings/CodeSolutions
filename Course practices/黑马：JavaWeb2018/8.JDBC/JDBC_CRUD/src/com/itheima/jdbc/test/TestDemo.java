package com.itheima.jdbc.test;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.junit.jupiter.api.Test;

import com.itheima.jdbc.util.JDBCUtil;

/**   
 * @ClassName:  TestDemo   
 * @Description:TODO(使用JUnit执行单元测试)   
 * @author: SourDumplings
 * @date:   2019年2月2日 下午4:57:44   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public class TestDemo
{
	@Test
	public void testQuery()
	{
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		
		try
		{
			// 1.获取连接对象
			conn = JDBCUtil.getConnection();
			
			// 2.根据连接对象得到Statement
			st = conn.createStatement();
			
			// 3.执行sql语句，返回ResultSet
			String sql = "select * from t_stu";
			rs = st.executeQuery(sql);
			
			// 4.遍历获取结果集
			while (rs.next())
			{
				String name = rs.getString("name");
				int age = rs.getInt("age");
				System.out.println("name: " + name + ", age: " + age);
			}
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally 
		{
			JDBCUtil.release(conn, rs, st);
		}
	}
	
	@Test
	public void testInsert()
	{
		Connection conn = null;
		Statement st = null;
		
		try
		{
			// 1.获取连接对象
			conn = JDBCUtil.getConnection();
			
			// 2.根据连接对象得到Statement
			st = conn.createStatement();
			
			// 3.执行sql语句，执行添加，返回的是影响的行数
			String sql = "insert into t_stu values(null, 'obama', 59)";
			int result = st.executeUpdate(sql);
			
			// 4.如果影响的行数大于零表示操作成功
			if (result > 0)
			{
				System.out.println("添加成功！");
			}
			else
			{
				System.out.println("添加失败！");
			}
			
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally 
		{
			JDBCUtil.release(conn, st);
		}
	}

	@Test
	public void testDelete()
	{
		Connection conn = null;
		Statement st = null;
		
		try
		{
			// 1.获取连接对象
			conn = JDBCUtil.getConnection();
			
			// 2.根据连接对象得到Statement
			st = conn.createStatement();
			
			// 3.执行sql语句，执行添加，返回的是影响的行数
			String sql = "delete from t_stu where name = 'obama'";
			int result = st.executeUpdate(sql);
			
			// 4.如果影响的行数大于零表示操作成功
			if (result > 0)
			{
				System.out.println("删除成功！");
			}
			else
			{
				System.out.println("删除失败！");
			}
			
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally 
		{
			JDBCUtil.release(conn, st);
		}
	}
	
	@Test
	public void testUpdate()
	{
		Connection conn = null;
		Statement st = null;
		
		try
		{
			// 1.获取连接对象
			conn = JDBCUtil.getConnection();
			
			// 2.根据连接对象得到Statement
			st = conn.createStatement();
			
			// 3.执行sql语句，执行添加，返回的是影响的行数
			String sql = "update t_stu set age = 26 where name = 'qyq'";
			int result = st.executeUpdate(sql);
			
			// 4.如果影响的行数大于零表示操作成功
			if (result > 0)
			{
				System.out.println("更新成功！");
			}
			else
			{
				System.out.println("更新失败！");
			}
			
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally 
		{
			JDBCUtil.release(conn, st);
		}
	}
}
