<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>部门修改</title>
</head>
<body>
	<ul>
		<li>
			<form method="post" action="UpdatePartServlet">
				原部门名称：<input name="old" /> 新部门名称：<input name="new"/> 
				<button type="submit">提交</button>
			</form>
		</li>
	</ul>
</body>
</html>