<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>Insert title here</title>
	<script type="text/javascript" src="js/jquery-1.11.0.js">
	</script>
	<script type="text/javascript">
		function post()
		{
			$.post("/day16/DemoServlet03", { name: "zhangsan", age: "18" }, function (data, status)
			{
				// alert("回来数据了：" + data);
				// 想要放数据到div中去
				$("#div01").html("<font color='red'>" + data + "</font>");
			});


		}
	</script>
</head>

<body>
	<input type="button" onclick="post()" value="使用jQuery演示post方法">

	<div id="div01" style="width: 100px; height: 100px; border: 1px solid blue">


	</div>
</body>

</html>