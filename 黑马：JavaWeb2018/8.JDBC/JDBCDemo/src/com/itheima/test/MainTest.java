package com.itheima.test;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.itheima.util.JDBCUtil;

public class MainTest
{

	public static void main(String[] args)
	{
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		try
		{
			conn = JDBCUtil.getConnection();
			// 3.创建statement，跟数据库打交道一定需要这个对象
			st = conn.createStatement();
			
			// 4.执行查询，得到结果集
			String sql = "select * from t_stu";
			rs = st.executeQuery(sql);
			
			while (rs.next())
			{
				int id = rs.getInt("id");
				String name = rs.getString("name");
				int age = rs.getInt("age");
				
				System.out.println("id = " + id + "===name = " +
						name + "==age = " + age);
				
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
