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
		function get()
		{
			$.get("/day16/DemoServlet02", function (data, status)
			{
				// alert("结果是：" + data);

				// $("#div01") == document.getElemetById("div01")
				// $("#div01").val(data); // val 用于设置元素里面有values的属性值，不能用
				// $("#div01").html("<font color='red'>" + data + "</font>"); // html可用标签等html样式，text不行
				$("#div01").text("text:" + data);
			});
		}
	</script>
</head>

<body>
	<input type="button" onclick="get()" value="使用jQuery演示get方法">

	<div id="div01" style="width: 100px; height: 100px; border: 1px solid blue">


	</div>
</body>

</html>