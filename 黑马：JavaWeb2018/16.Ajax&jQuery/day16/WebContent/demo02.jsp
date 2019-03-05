<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>

<script type="text/javascript">
	//1. 创建对象
	function ajaxFunction()
	{
		var xmlHttp;
		try
		{ // Firefox, Opera 8.0+, Safari
			xmlHttp = new XMLHttpRequest();
		}
		catch (e)
		{
			try
			{// Internet Explorer
				xmlHttp = new ActiveXObject("Msxml2.XMLHTTP");
			}
			catch (e)
			{
				try
				{
					xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
				}
				catch (e)
				{
				}
			}
		}

		return xmlHttp;
	}

	function post()
	{
		//1. 创建对象
		var request = ajaxFunction();

		//2. 发送请求
		request.open("POST", "/day16/DemoServlet01", true);

		//想获取服务器传送过来的数据， 加一个状态的监听。 
		request.onreadystatechange = function()
		{
			if (request.readyState == 4 && request.status == 200)
			{
				alert("post：" + request.responseText);
			}
		}

		//如果使用的是post方式带数据，那么 这里要添加头， 说明提交的数据类型是一个经过url编码的form表单数据
		request.setRequestHeader("Content-type",
				"application/x-www-form-urlencoded");

		//带数据过去  ， 在send方法里面写表单数据。 
		request.send("name=aobama&age=19");
	}
</script>

</head>
<body>
	<h3>
		<a href="" onclick="post()">使用Ajax方式发送Post请求</a>
	</h3>
</body>
</html>