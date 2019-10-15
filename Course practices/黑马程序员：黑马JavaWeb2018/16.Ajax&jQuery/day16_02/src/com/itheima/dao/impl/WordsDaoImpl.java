package com.itheima.dao.impl;

import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import com.itheima.dao.WordsDao;
import com.itheima.domain.WordBean;
import com.itheima.util.JDBCUtil02;

public class WordsDaoImpl implements WordsDao
{

	public List<WordBean> findWords(String word) throws SQLException
	{
		// TODO Auto-generated method stub
		QueryRunner runner = new QueryRunner(JDBCUtil02.getDataSource());
		String sql = "select * from words where word like ? limit ?";
		return runner.query(sql, new BeanListHandler<WordBean>(WordBean.class), word + "%", 5);
	}


}
