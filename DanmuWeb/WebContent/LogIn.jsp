<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="en" class="no-js">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<head>
<title>登录(Login)</title>
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
		<h1>登录(Login)</h1>
		<form action="Check" method="post">
			<input type="text" name="username" class="username"
				placeholder="请输入您的用户名！"> <input type="password"
				name="password" class="password" placeholder="请输入您的用户密码！">
			<%
				String error = request.getParameter("error");
				if (error!=null) {
			%><font color="red">用户名或密码错误！</font>
			<%
				}
			%>
			<input type="checkbox" name="box" class="box">两周内自动登录
			<button type="submit" class="submit_button">登录</button>
			<div class="error">
				<span>+</span>
			</div>
		</form>
		<a href="Register.jsp"><button class="submit_button">注册</button></a>
	</div>

	<!-- Javascript -->
	<script src="assets/js/jquery-1.8.2.min.js"></script>
	<script src="assets/js/supersized.3.2.7.min.js"></script>
	<script src="assets/js/supersized-init.js"></script>
	<script src="assets/js/scripts.js"></script>

</body>
<div style="text-align: center;"></div>
</html>