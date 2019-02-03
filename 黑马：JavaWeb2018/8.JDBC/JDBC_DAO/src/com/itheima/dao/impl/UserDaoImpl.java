package com.itheima.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

import com.itheima.dao.UserDao;
import com.itheima.util.JDBCUtil;

public class UserDaoImpl implements UserDao
{
	@Override
	public void insert(String username, String password)
	{
		Connection conn =  null;
		PreparedStatement ps = null;
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "insert into t_user values(null, ?, ?)";
			ps = conn.prepareStatement(sql);
			
			// 给占位符赋值，1代表是第一个?，永远是1开始
			ps.setString(1, username);
			ps.setString(2, password);
			
			int result = ps.executeUpdate();
			
			if (result > 0)
			{
				System.out.println("添加成功");
			}
			else
			{
				System.out.println("添加失败");
			}
			
		}
		catch (Exception e)
		{
			// TODO: handle exception
		}
		finally
		{
			JDBCUtil.release(conn, ps);
		}
	}

	@Override
	public void delete(int id)
	{
		// TODO Auto-generated method stub
		Connection conn =  null;
		PreparedStatement ps = null;
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "delete from t_user where id = ?";
			ps = conn.prepareStatement(sql);
			
			// 给占位符赋值，1代表是第一个?，永远是1开始
			ps.setInt(1, id);
			
			int result = ps.executeUpdate();
			
			if (result > 0)
			{
				System.out.println("删除成功");
			}
			else
			{
				System.out.println("删除失败");
			}
			
		}
		catch (Exception e)
		{
			// TODO: handle exception
		}
		finally
		{
			JDBCUtil.release(conn, ps);
		}
	}
	
	@Override
	public void update(int id, String username)
	{
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		Connection conn =  null;
		PreparedStatement ps = null;
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "update t_user set username = ? where id = ?";
			ps = conn.prepareStatement(sql);
			
			// 给占位符赋值，1代表是第一个?，永远是1开始
			ps.setString(1, username);
			ps.setInt(2, id);
			
			int result = ps.executeUpdate();
			
			if (result > 0)
			{
				System.out.println("更新成功");
			}
			else
			{
				System.out.println("更新失败");
			}
			
		}
		catch (Exception e)
		{
			// TODO: handle exception
		}
		finally
		{
			JDBCUtil.release(conn, ps);
		}
	}
	
	@Override
	public void findAll()
	{
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		
		try
		{
			conn = JDBCUtil.getConnection();
			st = conn.createStatement();
			String sql = "select * from t_user";
			rs = st.executeQuery(sql);
			
			while (rs.next())
			{
				String username = rs.getString("username");
				String password = rs.getString("password");
				
				System.out.println("username: " + username + ", password: " + password);
			}
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, rs, st);
		}
	}
	
	// 用Statement不安全
/*	@Override
	public void login(String username, String password)
	{
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		
		try
		{
			conn = JDBCUtil.getConnection();
			st = conn.createStatement();
			String sql = "select * from t_user where username = '"+ username +
					"' and password = '" + password + "'";
			rs = st.executeQuery(sql);
			
			if (rs.next())
			{
				System.out.println("登录成功！");
			}
			else
			{
				System.out.println("登录失败！");
			}
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, rs, st);
		}
	} */
	// 替换为PrepareStatment
	@Override
	public void login(String username, String password)
	{
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		try
		{
			conn = JDBCUtil.getConnection();
			String sql = "select * from t_user where username = ? and password = ?";
			
//			预先对SQL语句进行校验，?处不论传什么都会被看做是字符串，注意顺序别写串了
			ps = conn.prepareStatement(sql);
			ps.setString(1, username);
			ps.setString(2, password);
			
			rs = ps.executeQuery();
			
			if (rs.next())
			{
				System.out.println("登录成功！");
			}
			else
			{
				System.out.println("登录失败！");
			}
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, rs, ps);
		}
	}
}
