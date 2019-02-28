package com.itheima.c3p0;

import java.sql.Connection;
import java.sql.SQLException;

import com.itheima.util.JDBCUtil2;

public class Test
{
	public static void main(String[] args)
	{
		Connection conn = null;
		try
		{
			conn = JDBCUtil2.getConnection();
			
			conn.prepareStatement(null);
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
