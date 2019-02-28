package com.ithema.test;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import org.junit.Test;

import com.itheima.util.JDBCUtil;

public class TestDemo
{
	@Test
	public void test02()
	{
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		try
		{
			conn = JDBCUtil.getConnection();
			
			String sql = "update account set money = money - ? where id = ?";
			ps = conn.prepareStatement(sql);
			
			// 给id为1的扣100钱
			ps.setInt(1, 100);
			ps.setInt(2, 1);
			ps.executeUpdate();
			
			int a = 10 / 0;
			
			// 给id为2的加100钱
			ps.setInt(1, -100);
			ps.setInt(2, 2);
			ps.executeUpdate();
			
			
		}
		catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, rs, ps);
		}
		
	}	

	@Test
	public void testTransaction()
	{
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		try
		{
			conn = JDBCUtil.getConnection();
			
			// 默认的连接，事务就是自动提交的
			// 关闭自动提交
			conn.setAutoCommit(false);
			
			
			String sql = "update account set money = money - ? where id = ?";
			ps = conn.prepareStatement(sql);
			
			// 给id为1的扣100钱
			ps.setInt(1, 100);
			ps.setInt(2, 1);
			ps.executeUpdate();
			
			int a = 10 / 0;
			
			// 给id为2的加100钱
			ps.setInt(1, -100);
			ps.setInt(2, 2);
			ps.executeUpdate();
			
			// 成功：提交事务
			conn.commit();
			
			
		}
		catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
			
			// 失败了：回滚事务
			try
			{
				conn.rollback();
			}
			catch (SQLException e1)
			{
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		finally
		{
			JDBCUtil.release(conn, rs, ps);
		}
		
	}
}
