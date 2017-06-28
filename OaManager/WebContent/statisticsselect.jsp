<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>出勤统计查询</title>
</head>
<body>
	<form action="StatisticsSelectServlet" method="post">
		<input name="condition" />示例：2017-06-23或2017-06或张三<br />
		<input type="radio" name="type" value="day">按日查询<br/>
		<input type="radio" name="type" value="month">按月查询<br/>
		<input type="radio" name="type" value="name">按员工名查询<br/>
		<button type="submit">确认</button>
	</form>
	<table border="5">
		<tr>
			<td>员工姓名</td>
			<td>时间</td>
			<td>上班及病事假情况</td>
		</tr>
		<c:forEach items="${list }" var="log">
		<tr>
			<td>${log.worker.name }</td>
			<td>${log.time }</td>
			<td>${log.leave }</td>
		</tr>
		</c:forEach>
	</table>
</body>
</html>