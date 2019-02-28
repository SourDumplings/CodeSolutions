package com.itheima.dbcp;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Properties;

import javax.sql.DataSource;

import org.apache.commons.dbcp.BasicDataSourceFactory;
import org.junit.Test;

import com.itheima.util.JDBCUtil;

public class DBCPDemo02
{
	@Test
	public void testDBCP02()
	{
		Connection conn = null;
		PreparedStatement ps = null;
		
		try
		{
			BasicDataSourceFactory factory = new BasicDataSourceFactory();
			Properties properties = new Properties();
			InputStream is = new FileInputStream("src\\dbcpconfig.properties");
			properties.load(is);
			DataSource dataSource = factory.createDataSource(properties);
			
			// 2.得到连接对象
			conn = dataSource.getConnection();
			
			String sql = "insert into account values(null, ?, ?)";
			ps = conn.prepareStatement(sql);
			ps.setString(1, "liangchaowei");
			ps.setInt(2, 100);
			
			ps.executeUpdate();
			
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (FileNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (Exception e)
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
