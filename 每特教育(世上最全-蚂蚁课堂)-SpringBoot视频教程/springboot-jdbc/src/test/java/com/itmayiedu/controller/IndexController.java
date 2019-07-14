package com.itmayiedu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.itmayiedu.service.UserService;

@RestController
public class IndexController
{
	@Autowired
	private UserService userService;
	
	@RequestMapping("/index")
	public String index()
	{
		userService.createUser();
		return "add user success";
	}
}
