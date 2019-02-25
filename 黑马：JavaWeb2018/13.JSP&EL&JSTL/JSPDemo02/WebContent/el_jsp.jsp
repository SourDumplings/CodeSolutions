<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>
<%@page import="java.util.List"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

	<%
		pageContext.setAttribute("name", "page");
		request.setAttribute("name", "request");
		session.setAttribute("name", "session");
		application.setAttribute("name", "application");
	%>
	
	按普通手段取值<br>
	
	<%= pageContext.getAttribute("name")%>
	<%= request.getAttribute("name")%>
	<%= session.getAttribute("name")%>
	<%= application.getAttribute("name")%>
	
	使用EL表达式取出作用域中的值<br>
	
	${ pageScope.name }
	${ requestScope.name }
	${ sessionScope.name }
	${ applicationScope.name }
	
	<br>----------------------------------<br>
	
	<%
		String[] a = {"aa", "bb", "cc", "dd"};
		pageContext.setAttribute("array", a);
	
	%>
	
	使用EL表达式取出作用域中数组的值<br>
	
	${ array[0] }, ${ array[1] }, ${ array[2] }, ${ array[3] }
	
	<br>----------------集合数据------------------<br>
	
	<%
		List list = new ArrayList();
		list.add(1234);
		list.add("11");
		list.add("22");
		list.add("33");
		list.add("44");
		
		pageContext.setAttribute("li", a);
	
	%>
	
	使用EL表达式取出作用域中集合的值<br>
	
	${ li[0] }, ${ li[1] }, ${ li[2] }, ${ li[3] }
	
		
	<br>----------------集合数据------------------<br>

	<%
		Map map = new HashMap();
		map.put("name", "zhangsan");
		map.put("age", 18);
		map.put("address", "北京");
		map.put("address.aa", "深圳");
		
		pageContext.setAttribute("map", map);
	
	%>
	
	使用EL表达式取出作用域中Map的值<br>
	
	${ map.name }, ${ map.age }, ${ map.address }, ${ map["address.aa"] }

</body>
</html>