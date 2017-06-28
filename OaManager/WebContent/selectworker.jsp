<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查询人员</title>
</head>
<body>
	<c:if test="${empty list }">
		<c:redirect url="SelectWorkerServlet" />
	</c:if>
	<form method="post" action="SelectWorkerServlet">
		部门名或员工名:<input name="condition" />
		<button type="submit">查询</button>
	</form>
	<table border="5">
		<c:forEach items="${list }" var="worker">
			<tr>
				<td>${worker.name }</td>
				<td>${worker.part.name }</td>
			</tr>
		</c:forEach>
	</table>
	<a href="index.jsp">返回首页</a>
</body>
</html>