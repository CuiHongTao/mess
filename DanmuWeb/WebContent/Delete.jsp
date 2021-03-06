<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="en" class="no-js">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<head>
<title>确认密码</title>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta name="description" content="">
<meta name="author" content="">

<!-- CSS -->
<link rel="stylesheet" href="assets/css/reset.css">
<link rel="stylesheet" href="assets/css/supersized.css">
<link rel="stylesheet" href="assets/css/style.css">

<!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
<!--[if lt IE 9]>
            <script src="assets/js/html5.js"></script>
        <![endif]-->

</head>

<body>

	<div class="page-container">
		<h1>确认密码</h1>
		<form action="Delete" method="post">
			 <input type="password"
				name="deltext" class="password" placeholder="请输入您的用户密码！">
			<%
				String error = request.getParameter("error");
				if (error!=null) {
			%><font color="red">密码错误！</font>
			<%
				}
			%>
			<button type="submit" class="submit_button">确认</button>
		</form>
	</div>

	<!-- Javascript -->
	<script src="assets/js/jquery-1.8.2.min.js"></script>
	<script src="assets/js/supersized.3.2.7.min.js"></script>
	<script src="assets/js/supersized-init.js"></script>
	<script src="assets/js/scripts.js"></script>

</body>
<div style="text-align: center;"></div>
</html>