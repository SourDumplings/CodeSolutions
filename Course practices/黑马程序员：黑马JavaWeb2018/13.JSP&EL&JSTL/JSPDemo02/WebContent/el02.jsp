<%@page import="com.itheima.domain.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

	从域中取值。得先存值。
	<%
		// pageContext.setAttribute("name", "zhangsan");
		session.setAttribute("name", "lisi");
	%>
	
	<br>直接指定说了，到这个作用域里面去找这个值<br>
	${ pageScope.name }
	
	<br>先从page里面找，再request，再session，最后application<br>
	${ name }
	
	<br>指定从session中取值<br>
	${ sessionScope.name }
	
	<br>-----------------------------------------------<br>
	<%
		User user = new User("zhangsan", 18);
	
		session.setAttribute("u", user);
	%>
	
	${ u.name }, ${ u.age }
	
	${ a gt b }
	
	${ empty u }

</body>
</html>