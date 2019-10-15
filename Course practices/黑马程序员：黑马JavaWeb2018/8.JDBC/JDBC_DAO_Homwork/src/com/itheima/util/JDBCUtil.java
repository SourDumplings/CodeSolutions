package com.itheima.util;

import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;


/**   
 * @ClassName:  JDBCUtil   
 * @Description:TODO(这里用一句话描述这个类的作用)   
 * @author: SourDumplings
 * @date:   2019年2月2日 上午9:50:26   
 *     
 * @link: https://github.com/SourDumplings
 */ 
public class JDBCUtil
{
	static String driverClass = null;
	static String url = null;
	static String username = null;
	static String password = null;
	
	static
	{
		
		try
		{
			Properties properties = new Properties();
			// 文件写在src底下时，在类加载的时候顺便将文件也加载到bin中
			// 使用类加载器获取src底下的资源
//			InputStream is = JDBCUtil.class.getClassLoader().getResourceAsStream("jdbc.properties");
			// 文件在工程根目录底下时这么写
			InputStream is = new FileInputStream("jdbc.properties");
			
			// 导入输入流
			properties.load(is);
			
			// 读属性
			driverClass = properties.getProperty("driverClass");
			url = properties.getProperty("url");
			username = properties.getProperty("username");
			password = properties.getProperty("password");
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
		

	}
	
	/**   
	 * @Title: getConnection   
	 * @Description: TODO(获取连接对象)   
	 * @param: @return      
	 * @return: Connection      
	 * @throws   
	 */  
	public static Connection getConnection()
	{
		Connection conn = null;
		try
		{
			// 1.注册驱动
//			Driver中有个静态代码块 --> 类加载了就会执行。java.sql.DriverManager.registerDriver(new Driver());
//			这么干就会注册两回
//			DriverManager.registerDriver(new Driver());
			// 应该这么干，forName中是传入类的全路径地址
			Class.forName(driverClass).newInstance();
			// 2.建立连接 参数1：协议 + 访问的数据库，参数2：用户名，参数3：密码
			conn = DriverManager.getConnection(url, username, password);
		}
		catch (InstantiationException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IllegalAccessException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (ClassNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return conn;
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
		closeRs(rs);
		closeSt(st);
		closeConn(conn);
	}
	
	public static void release(Connection conn, Statement st)
	{
		closeSt(st);
		closeConn(conn);
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
