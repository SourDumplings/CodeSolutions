<%@page import="com.itheima.domain.User"%>
<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

<!-- 默认存到page里面 -->
<c:set var="name" value="zhangsan" scope="session"></c:set>

${ name }, ${ sessionScope.name }

<br>---------------------------------------<br>
<c:set var="age" value="18"></c:set>
<c:if test="${ age > 26 }">
	年龄大于了26岁
</c:if>
<c:if test="${ age > 16 }" var="flag" scope="session">
	年龄大于了16岁
</c:if>

${ flag }

<br>------------------------------------------<br>
<c:forEach begin="1" end="10" var="i" step="2">
	${ i }
</c:forEach>

<br>---------------------------------------------------<br>
<%
	List list = new ArrayList();
	
	list.add(new User("zhangsan", 18));
	list.add(new User("lisi", 28));
	list.add(new User("wangwu", 38));
	list.add(new User("maliu", 48));
	list.add(new User("qianqi", 58));
	
	pageContext.setAttribute("list", list);
%>

<c:forEach var="user" items="${list }">
	${user.name } ---- ${user.age }
</c:forEach>

</body>
</html>