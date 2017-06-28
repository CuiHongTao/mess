<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>删除人员</title>
</head>
<body>
	<form action="DeletWorkerServlet" method="post">
		员工名：<input name="name">
		<button type="submit">删除</button>
	</form>
</body>
</html>