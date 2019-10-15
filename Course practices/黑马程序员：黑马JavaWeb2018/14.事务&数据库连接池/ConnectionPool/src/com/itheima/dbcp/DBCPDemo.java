package com.itheima.dbcp;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import org.apache.commons.dbcp.BasicDataSource;
import org.junit.Test;

import com.itheima.util.JDBCUtil;

public class DBCPDemo
{
	@Test
	public void testDBCP01()
	{
		// 1.构建数据源对象
		BasicDataSource dataSource = new BasicDataSource();
		
		// 连的是什么类型的数据库，访问的是哪个数据库以及用户名密码要指明，实际中常以配置文件的方式去做
		dataSource.setDriverClassName("com.mysql.jdbc.Driver");
		// 主协议:子协议://本地:/数据库
		dataSource.setUrl("jdbc:mysql://localhost/bank");
		dataSource.setUsername("root");
		dataSource.setPassword("cz0929");
		
		
		Connection conn = null;
		PreparedStatement ps = null;
		
		try
		{
			// 2.得到连接对象
			conn = dataSource.getConnection();
			
			String sql = "insert into account values(null, ?, ?)";
			ps = conn.prepareStatement(sql);
			ps.setString(1, "admin");
			ps.setInt(2, 1000);
			
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
