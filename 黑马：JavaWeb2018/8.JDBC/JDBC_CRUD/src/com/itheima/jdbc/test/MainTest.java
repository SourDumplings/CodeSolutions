package com.itheima.jdbc.test;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.itheima.jdbc.util.JDBCUtil;

public class MainTest
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		// 查询
		
		
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

}
