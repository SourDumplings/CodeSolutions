<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Insert title here</title>
</head>
<body> 
<table border="1" width="100%">
	<tr>
		<td>商品名称</td>
		<td>市场价格</td>
		<td>商场价格</td>
		<td>商品图片</td>
	</tr>
	<c:if test="${empty page.list }">
		<tr><td colspan="4">暂无数据</td></tr>
	</c:if>
	<c:if test="${not empty page.list }">
		<c:forEach items="${page.list}" var="p">
			<tr>
				<td>${p.pname}</td>
				<td>${p.market_price}</td>
				<td>${p.shop_price}</td>
				<td>
					<img src="${pageContext.request.contextPath}/${p.pimage}" width="50px"/>
				</td>
			</tr>
		</c:forEach>
	</c:if>
</table>

	<%@include file="/pageFile.jsp" %>

</body>
</html>