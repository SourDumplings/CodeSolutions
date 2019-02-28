package com.itheima.c3p0;

import java.beans.PropertyVetoException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import org.junit.Test;

import com.itheima.util.JDBCUtil;
import com.mchange.v2.c3p0.ComboPooledDataSource;

public class C3P0Demo
{
	@Test
	public void testC3P0()
	{
		// 1.创建DataSource
		ComboPooledDataSource dataSource = new ComboPooledDataSource();
		
		Connection conn = null;
		PreparedStatement ps = null;
		
		try
		{
			// 2.设置连接数据库的信息
			// 忘记了：去以前的代码或者去JDBC文档中找，开发中常用配置文件的方式
			dataSource.setDriverClass("com.mysql.jdbc.Driver");
			dataSource.setJdbcUrl("jdbc:mysql://localhost/bank");
			dataSource.setUser("root");
			dataSource.setPassword("cz0929");
			
			// 3.得到连接对象
			conn = dataSource.getConnection();
			
			String sql = "insert into account values(null, ?, ?)";
			ps = conn.prepareStatement(sql);
			ps.setString(1, "adm121in");
			ps.setInt(2, 10012);
			
			ps.executeUpdate();
			
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (PropertyVetoException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			JDBCUtil.release(conn, null, ps);
		}
	}
}
