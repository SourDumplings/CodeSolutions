package com.cz.login.demo.service.impl;

import com.cz.login.demo.dao.UserDao;
import com.cz.login.demo.dao.impl.UserDaoImpl;
import com.cz.login.demo.entity.User;
import com.cz.login.demo.service.UserService;

/**
 * 业务逻辑层
 *
 * @author CHANG Zheng
 * @title: UserServiceImpl
 * @projectName 千峰教育：走向单体地狱
 * @description: TODO
 * @date 2019/10/2021:23
 */
public class UserServiceImpl implements UserService
{
    // 数据访问层的具体实现
    private UserDao userDao = new UserDaoImpl();

    /**
     * 登录
     *
     * @param loginId
     * @param loginPwd
     * @return
     */
    public User login(String loginId, String loginPwd)
    {
        return userDao.login(loginId, loginPwd);
    }
}
