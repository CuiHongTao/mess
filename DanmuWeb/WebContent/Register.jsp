<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="en" class="no-js">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>注册</title>
</head>
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
		<h1>注册</h1>
		<form action="Register" method="post">
			<input type="text" name="username" class="username"
				placeholder="请输入您的用户名！"> <input type="password"
				name="password" class="password" placeholder="请输入您的用户密码！"> <input
				type="password" name="password2" class="password"
				placeholder="请确认您的用户密码！">
			<%
				String error = request.getParameter("error");
				if (error != null){if (error.equals("1"))
			%><font color="red">用户名重复！</font>
			<%
				if (error.equals("2"))%><font color="red">密码不一致！</font>
			<%
				if (error.equals("3"))%><font color="red">用户名不能为空！</font>
			<%
				if (error.equals("4"))%><font color="red">密码能为空！</font><% }
			%>
			<button type="submit" class="submit_button">注册</button>
			<div class="error">
				<span>+</span>
			</div>
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