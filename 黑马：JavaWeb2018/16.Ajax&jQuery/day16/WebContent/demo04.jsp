<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>

<script type="text/javascript" src="js/jquery-1.11.0.js"></script>

<script type="text/javascript">
	function load()
	{

		// $("#aaa").val("aaa");

		//$("#text01") --- document.getElementById("text01");
 		$("#aaa").load("/day16/DemoServlet02",
				function(responseText, statusTXT, xhr)
				{
					//alert("jieguo:"+responseText);
					//找到id为text01的元素， 设置它的value属性值为 responseText 对应的值
					$("#aaa").val(responseText);
				});
	}
</script>
</head>
<body>

	<!-- <h3><a href="" onclick="load()">使用JQuery执行load方法</a></h3> -->
	<h3>
		<input type="button" onclick="load()" value="使用JQuery执行load方法">
	</h3>

	<input type="text" id="aaa">

</body>
</html>