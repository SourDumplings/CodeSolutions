package com.cz.login.demo.dao.impl;

import com.cz.login.demo.dao.UserDao;
import com.cz.login.demo.entity.User;

/**
 * @author CHANG Zheng
 * @title: UserDaoImpl
 * @projectName 千峰教育：走向单体地狱
 * @description: TODO
 * @date 2019/10/2019:54
 */
public class UserDaoImpl implements UserDao
{

    /**
     * 用户登录
     *
     * @param
     * @return java.lang.String
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/20 19:55
     */
    public User login(String loginId, String loginPwd)
    {
        // 方法1：
        // 直接根据loginId和loginPwd查询出这个用户信息
        // 这种方式不安全，会有可能SQL注入，不安全
/*        if ("admin".equals(loginId) && "admin".equals(loginPwd))
        {
            return "成功";
        }*/

        // 方法2：
        User user = null;
        // 用loginId查询用户信息
        if ("admin".equals(loginId))
        {
            // 再根据传入的密码匹配
            if ("admin".equals(loginPwd))
            {
                user = new User();
                user.setLoginId("admin");
                user.setLoginPwd("admin");
                user.setUsername("Lusifer");
            }
        }

        return user;
    }
}
