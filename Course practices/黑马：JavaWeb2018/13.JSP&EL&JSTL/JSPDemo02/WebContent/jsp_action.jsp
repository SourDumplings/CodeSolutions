<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%-- 	<jsp:include page=""></jsp:include>
	<jsp:param value="" name=""/>
	<jsp:forward page=""></jsp:forward> --%>
	
	这是jsp_action的页面
<%-- 	<%@include file="other02.jsp" %> --%>
	<%-- <jsp:include page="other02.jsp"></jsp:include> --%>
	
	<%-- <jsp:forward page="other02.jsp"></jsp:forward> --%>
<%-- 	等同于以下代码：
<%
	request.getRequestDispatcher("other02.jsp").forward(request, response);
%> --%>

	<jsp:forward page="other02.jsp">
		<jsp:param value="beijing" name="address"/>
	</jsp:forward>
</body>
</html>