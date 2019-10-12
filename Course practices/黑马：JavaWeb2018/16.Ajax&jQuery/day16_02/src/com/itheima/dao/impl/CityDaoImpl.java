package com.itheima.dao.impl;

import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import com.itheima.dao.CityDao;
import com.itheima.domain.CityBean;
import com.itheima.util.JDBCUtil02;

public class CityDaoImpl implements CityDao
{

	public List<CityBean> findCity(int pid) throws SQLException
	{
		// TODO Auto-generated method stub
		QueryRunner runner = new QueryRunner(JDBCUtil02.getDataSource());
		String sql = "select * from cities where pid = ?";
		return runner.query(sql, new BeanListHandler<CityBean>(CityBean.class), pid); 
	}

}
