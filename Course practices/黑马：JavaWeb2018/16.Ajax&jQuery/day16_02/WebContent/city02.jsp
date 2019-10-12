<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Insert title here</title>
    <script type="text/javascript" src="js/jquery-1.11.0.js"></script>
    <!-- 引用的是json的处理方法 -->
    <script type="text/javascript" src="js/city_json.js"></script>

</head>

<body>
    省份：<select name="province" id="province">
        <option value="">-请选择-
        <option value="1">广东
        <option value="2">湖南
        <option value="3">湖北
        <option value="4">四川
    </select>
    城市：<select name="cities" id="cities">
        <option value="">-请选择-
    </select>

</body>

</html>