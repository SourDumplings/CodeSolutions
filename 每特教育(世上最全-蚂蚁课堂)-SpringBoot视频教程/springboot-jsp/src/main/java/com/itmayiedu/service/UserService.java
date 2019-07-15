package com.itmayiedu.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.itmayiedu.mapper.UserMapper;

@Service
public class UserService
{
	@Autowired
	private UserMapper userMapper;
	
	@Transactional
	public int addUser(String name, Integer age)
	{
		int result = userMapper.insertUser(name, age);
		int i = 1 / 0;
		return result;
	}
}
