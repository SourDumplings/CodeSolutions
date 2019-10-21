package com.cz.login.demo.web.controller;

import com.cz.login.demo.entity.User;
import com.cz.login.demo.service.UserService;
import com.cz.login.demo.service.impl.UserServiceImpl;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * 登录控制器
 *
 * @author CHANG Zheng
 * @title: LoginController
 * @projectName 千峰教育：走向单体地狱
 * @description: TODO
 * @date 2019/10/2021:51
 */

public class LoginController extends HttpServlet
{
    private UserService userService = new UserServiceImpl();

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
        throws ServletException, IOException
    {
        String loginId = req.getParameter("loginId");
        String loginPwd = req.getParameter("loginPwd");

        User user = userService.login(loginId, loginPwd);

        // 登录失败
        if (user == null)
        {
            req.getRequestDispatcher("/fail.jsp").forward(req, resp);
        }
        // 登录成功
        else
        {
            req.getRequestDispatcher("/success.jsp").forward(req, resp);
        }

    }
}
