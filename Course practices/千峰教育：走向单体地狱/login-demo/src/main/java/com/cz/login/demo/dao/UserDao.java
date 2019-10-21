package com.cz.login.demo.dao;

import com.cz.login.demo.entity.User;

/**
 * 用户数据访问
 *
 * @author CHANG Zheng
 * @title: UserDao
 * @projectName 千峰教育：走向单体地狱
 * @description: TODO
 * @date 2019/10/2019:50
 */
public interface UserDao
{
    public User login(String loginId, String loginPwd);
}
