package com.itheima.dao.impl;

import java.sql.SQLException;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;

import com.itheima.dao.UserDao;
import com.itheima.domain.UserBean;
import com.itheima.util.JDBCUtil2;

public class UserDaoImpl implements UserDao
{

	public UserBean login(UserBean user) throws SQLException
	{
		// TODO Auto-generated method stub
		QueryRunner runner = new QueryRunner(JDBCUtil2.getDataSource());
		String sql = "select * from t_user where username = ? and password = ?";
		return runner.query(sql, new BeanHandler<UserBean>(UserBean.class), user.getUsername(), user.getPassword());
	}

}
