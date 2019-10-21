package com.cz.login.demo.entity;

import java.io.Serializable;

/**
 * 用户表
 *
 * @author CHANG Zheng
 * @title: User
 * @projectName 千峰教育：走向单体地狱
 * @description: TODO
 * @date 2019/10/2019:44
 */
public class User implements Serializable
{

    private String username;
    private String loginId;
    private String loginPwd;

    public String getUsername()
    {
        return username;
    }

    public void setUsername(String username)
    {
        this.username = username;
    }

    public String getLoginId()
    {
        return loginId;
    }

    public void setLoginId(String loginId)
    {
        this.loginId = loginId;
    }

    public String getLoginPwd()
    {
        return loginPwd;
    }

    public void setLoginPwd(String loginPwd)
    {
        this.loginPwd = loginPwd;
    }

    @Override
    public String toString()
    {
        return "User{" +
            "username='" + username + '\'' +
            ", loginId='" + loginId + '\'' +
            ", loginPwd='" + loginPwd + '\'' +
            '}';
    }
}
