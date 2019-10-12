package com.itheima.c3p0;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import org.junit.Test;

import com.itheima.util.JDBCUtil;
import com.mchange.v2.c3p0.ComboPooledDataSource;

public class C3P0Demo02
{
	@Test
	public void testC3P0()
	{
		// 1.创建DataSource，自动会加载名为c3p0-config.xml的配置文件
		ComboPooledDataSource dataSource = new ComboPooledDataSource();
		
		Connection conn = null;
		PreparedStatement ps = null;
		
		try
		{
			// 2.设置连接数据库的信息
			
			// 3.得到连接对象
			conn = dataSource.getConnection();
			
			String sql = "insert into account values(null, ?, ?)";
			ps = conn.prepareStatement(sql);
			ps.setString(1, "wangwu");
			ps.setInt(2, 2300);
			
			ps.executeUpdate();
			
		}
		catch (SQLException e)
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
