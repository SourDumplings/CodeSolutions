package com.itheima.util;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import org.junit.Test;

public class TestPool
{
	@Test
	public void testPool()
	{
		MyDataSource dataSource = null;
		Connection conn = null;
		
		PreparedStatement ps = null;
		int rs = 0;
		try
		{
			dataSource = new MyDataSource();
			
			// 这里得到的是我们包装之后的类，ConnectionWrap
			conn = dataSource.getConnection();
			
			String sql = "insert into account values(null, 'xilali', 10)";
			ps = conn.prepareStatement(sql);
			rs = ps.executeUpdate();
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			try
			{
				ps.close();
			}
			catch (SQLException e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
//			// 归还连接
//			dataSource.addBack(conn);
			
			JDBCUtil.release(conn, null, ps);
		}
	}
}
