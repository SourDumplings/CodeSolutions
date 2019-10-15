package com.itheima.dao.impl;

import java.sql.SQLException;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import com.itheima.dao.UserDao;
import com.itheima.util.JDBCUtil02;

public class UserDaomImpl implements UserDao
{

	@Override
	public boolean checkUserName(String username) throws SQLException
	{
		QueryRunner runner = new QueryRunner(JDBCUtil02.getDataSource());

		String sql = "select count(*) from t_user where username =?";

		runner.query(sql, new ScalarHandler(), username);

		Long result = (Long) runner.query(sql, new ScalarHandler(), username);
		return result > 0;
	}

}
