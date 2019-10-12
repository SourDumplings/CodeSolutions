package com.itheima.dao;

import java.sql.SQLException;
import java.util.List;

import com.itheima.domain.CityBean;

public interface CityDao
{
	List<CityBean> findCity(int pid) throws SQLException;
}
