package com.itheima.dbutils;

import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.junit.Test;

import com.itheima.domain.Account;
import com.mchange.v2.c3p0.ComboPooledDataSource;

public class TestDBUtils
{
	@Test
	public void testInsert()
	{
		ComboPooledDataSource dataSource = new ComboPooledDataSource();
		
		
		// DBUtils只是帮我们简化了CRUD的代码，但是连接的创建和获取工作不在其工作范围
		QueryRunner queryRunner = new QueryRunner(dataSource);
		
		// 增删改
		try
		{
			// 增加
//			queryRunner.update("insert into account values(null, ?, ?)", "aa", 12345);

			// 删除
//			queryRunner.update("delete from account where id = ?", 5);
			
			// 更新
//			queryRunner.update("update account set money = ? where id = ?", 10000, 6);
		
			// 查询
			// 去执行查询，查询到的数据还是在那个ResultSet里面。然后调用下面的Handler方法，由用户手动去封装
			// 使用接口-匿名类
			/*Account account = queryRunner.query("select * from account where id = ?", new ResultSetHandler<Account>()
					{

						@Override
						public Account handle(ResultSet rs) throws SQLException
						{
							// TODO Auto-generated method stub
							Account account = new Account();
							
							while (rs.next())
							{
								String name = rs.getString("name");
								int money = rs.getInt("money");
							
								account.setMoney(money);
								account.setName(name);
							}

							return account;
						}
						
					}, 6);*/
			// 使用已有的接口实现类，通过类的字节码得到类的实例
			// 查询单个对象
//			Account account = queryRunner.query("select * from account where id = ?",
			// new BeanHandler<Account>(Account.class), 7);
			
//			System.out.println(account.toString());
			
			List<Account> list = queryRunner.query("select * from account",
					new BeanListHandler<Account>(Account.class));
			
			for (Account account : list)
			{
				System.out.println(account.toString());
			}
			
		}
		catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
