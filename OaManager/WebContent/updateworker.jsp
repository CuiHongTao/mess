<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>修改人员</title>
</head>
<body>
	<ul>
		<li>
			<form method="post" action="UpdateWorkerServlet">
				原员工名字：<input name="oldname" /> 新员工名字：<input name="newname" />新员工部门：<input
					name="newpart" />
				<button type="submit">提交</button>
			</form>
		</li>
	</ul>
</body>
</html>