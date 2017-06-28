<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>未打卡登记</title>
</head>
<body>
	<form method="post" action="MakeUpServlet">
		姓名：<input name="name">原因：<input name="leave">
		<button type="submit">登记</button>
	</form>
</body>
</html>