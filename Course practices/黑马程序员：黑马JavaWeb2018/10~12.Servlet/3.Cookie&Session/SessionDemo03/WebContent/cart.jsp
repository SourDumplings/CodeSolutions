<%@page import="java.util.Map"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h2>您的购物车的商品如下：</h2>
	<%
		// 1.先获取到map
		Map<String, Integer> map = (Map<String, Integer>)session.getAttribute("cart");
		
		// 2.遍历Map
		if (map != null)
		{
			for (String key : map.keySet())
			{
				int value = map.get(key);
				// key商品名称，value是商品个数
	%>
				<h3>名称：<%=key %> 数量：<%=value %></h3><br>
	<%
			}
		}
	
	%>
	
	<a href="ClearCartServlet"><h4>清空购物车</h4></a>
</body>
</html>