<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<h3>这是04的界面</h3><br>

取出四个作用域中的值<br>
<%=pageContext.getAttribute("name") %>
<%=request.getAttribute("name") %>
<%=session.getAttribute("name") %>
<%=application.getAttribute("name") %>
</body>
</html>