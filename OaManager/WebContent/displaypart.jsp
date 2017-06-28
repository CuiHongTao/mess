<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>部门显示</title>
</head>
<body>
	<c:if test="${empty list }">
		<c:redirect url="DisplayPartServlet" />
	</c:if>
	<ul>
		<c:forEach items="${list }" var="part">
			<li>${part.name }</li>
		</c:forEach>
	</ul>
	<a href="index.jsp">返回首页</a>
</body>
</html>