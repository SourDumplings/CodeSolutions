package com.cz.login.demo.service;

import com.cz.login.demo.entity.User;

/**
 * @author CHANG Zheng
 * @title: UserService
 * @projectName 千峰教育：走向单体地狱
 * @description: TODO
 * @date 2019/10/2021:21
 */
public interface UserService
{
    public User login(String loginId, String loginPwd);
}
