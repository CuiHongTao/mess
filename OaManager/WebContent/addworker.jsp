<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>添加人员</title>
</head>
<body>
	<form action="AddWorkerServlet" method="post">
		新员工名称：<input name="name" />
		所属部门：<input name="part"/>
		<button type="submit">提交</button>
	</form>
</body>
</html>