<%--
  Created by IntelliJ IDEA.
  User: CHANG Zheng
  Date: 2019/10/20
  Time: 21:49
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录</title>
</head>
<body>
    <form action="${pageContext.request.contextPath}/login" method="post">
        <input name="loginId" type="text">
        <input name="loginPwd" type="password">
        <input type="submit" value="登录">
    </form>
</body>
</html>
