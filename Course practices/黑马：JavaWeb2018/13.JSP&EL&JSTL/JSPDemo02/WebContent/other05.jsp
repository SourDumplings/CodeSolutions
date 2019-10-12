<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h3>这是other05的页面</h3><br> <!-- 等价于out.write输出 -->

<%
	out.write("这是使用out对象输出的内容");
%>

<%
	response.getWriter().write("这是使用response对象输出的内容");
%>
</body>
</html>