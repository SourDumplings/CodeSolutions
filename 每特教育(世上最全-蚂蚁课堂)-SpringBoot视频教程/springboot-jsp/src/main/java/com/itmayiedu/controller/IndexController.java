package com.itmayiedu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.itmayiedu.entity.UserEntity;
import com.itmayiedu.mapper.UserMapper;

@Controller
public class IndexController
{
	@Autowired
	private UserMapper userMapper;
	
	@RequestMapping("/index")
	public String index()
	{
		return "index";
	}
	
	@ResponseBody
	@RequestMapping("/getUser")
	public UserEntity getUser(String name)
	{
		return userMapper.findName(name);
	}
}
