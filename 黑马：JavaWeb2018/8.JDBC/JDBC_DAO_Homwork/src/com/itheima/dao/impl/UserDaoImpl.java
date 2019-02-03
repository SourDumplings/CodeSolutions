package com.itheima.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.LinkedList;
import java.util.List;

import com.itheima.dao.User;
import com.itheima.dao.UserDao;
import com.itheima.util.JDBCUtil;

public class UserDaoImpl implements UserDao
{
	@Override
	public int insert(String username, String password)
	{
		Connection conn =  null;
		PreparedStatement ps = null;
		int ret = 0;
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "insert into t_user values(null, ?, ?)";
			ps = conn.prepareStatement(sql);
			
			// 给占位符赋值，1代表是第一个?，永远是1开始
			ps.setString(1, username);
			ps.setString(2, password);
			
			ret = ps.executeUpdate();
			
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, ps);
		}
		return ret;
	}

	@Override
	public int delete(int id)
	{
		// TODO Auto-generated method stub
		Connection conn =  null;
		PreparedStatement ps = null;
		int ret = 0;
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "delete from t_user where id = ?";
			ps = conn.prepareStatement(sql);
			
			// 给占位符赋值，1代表是第一个?，永远是1开始
			ps.setInt(1, id);
			
			ret = ps.executeUpdate();
			
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, ps);
		}
		return ret;
	}
	
	@Override
	public int update(int id, String username)
	{
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		Connection conn =  null;
		PreparedStatement ps = null;
		int ret = 0;
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "update t_user set username = ? where id = ?";
			ps = conn.prepareStatement(sql);
			
			// 给占位符赋值，1代表是第一个?，永远是1开始
			ps.setString(1, username);
			ps.setInt(2, id);
			
			ret = ps.executeUpdate();
			
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, ps);
		}
		return ret;
	}
	
	@Override
	public List<User> findAll()
	{
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		LinkedList<User> ret = new LinkedList<User>();
		
		try
		{
			conn = JDBCUtil.getConnection();
			st = conn.createStatement();
			String sql = "select * from t_user";
			rs = st.executeQuery(sql);
			
			while (rs.next())
			{
				int id = rs.getInt("id");
				String username = rs.getString("username");
				String password = rs.getString("password");
				
				ret.add(new User(id, username, password));
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
		return ret;
	}
	
	@Override
	public User login(String username, String password)
	{
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		User ret = null;
		
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
				int id = rs.getInt("id");
				String usr = rs.getString("username");
				String psw = rs.getString("password");
				ret = new User(id, usr, psw);
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
		return ret;
	}
}
