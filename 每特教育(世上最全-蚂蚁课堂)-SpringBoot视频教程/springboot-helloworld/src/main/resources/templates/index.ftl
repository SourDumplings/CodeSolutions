<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	${name}
	<#if sex == 1>
	女
	<#elseif sex == 0>
	男
	<#else>
	妖
	</#if>
	
	<#list userList as user>
		${user}
	</#list>
</body>
</html>