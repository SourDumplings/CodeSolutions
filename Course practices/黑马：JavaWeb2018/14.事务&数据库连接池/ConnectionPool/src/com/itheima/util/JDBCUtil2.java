package com.itheima.util;

import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

import com.mchange.v2.c3p0.ComboPooledDataSource;


/**   
 * @ClassName:  JDBCUtil   
 * @Description:TODO(这里用一句话描述这个类的作用)   
 * @author: SourDumplings
 * @date:   2019年2月2日 上午9:50:26   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public class JDBCUtil2
{
	static ComboPooledDataSource dataSource = null;
	static
	{
		dataSource = new ComboPooledDataSource();
	}
	
	/**
	 * @throws SQLException    
	 * @Title: getConnection   
	 * @Description: TODO(获取连接对象)   
	 * @param: @return      
	 * @return: Connection      
	 * @throws   
	 */  
	public static Connection getConnection() throws SQLException
	{
		return dataSource.getConnection();
	}
	
	/**   
	 * @Title: release   
	 * @Description: TODO（释放资源）
	 * @param: @param conn
	 * @param: @param rs
	 * @param: @param st      
	 * @return: void      
	 * @throws   
	 */  
	public static void release(Connection conn, ResultSet rs, Statement st)
	{
		closeConn(conn);
		closeRs(rs);
		closeSt(st);
	}
	
	private static void closeRs(ResultSet rs)
	{
		try
		{
			if (rs != null)
			{
				rs.close();
			}

		}
		catch (SQLException e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			rs = null;
		}
	}
	private static void closeSt(Statement st)
	{
		try
		{
			if (st != null)
			{
				st.close();
			}
			
		}
		catch (SQLException e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			st = null;
		}
	}
	private static void closeConn(Connection conn)
	{
		try
		{
			if (conn != null)
			{
				conn.close();
			}
			
		}
		catch (SQLException e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		finally
		{
			conn = null;
		}
	}
	
}
