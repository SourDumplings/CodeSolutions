package com.itmayiedu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import com.itmayiedu.service.UserService;

@Service
public class UserServiceImpl implements UserService
{
	@Autowired
	private JdbcTemplate jdbcTemplate;
	
	public void createUser()
	{
		// TODO Auto-generated method stub
		jdbcTemplate.update("insert into users values(null, ?, ?);", "lisi", 20);
	}

}
