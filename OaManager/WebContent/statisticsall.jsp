<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>出勤统计</title>
</head>
<body>
	期间：
	<form action="StatisticsAllServlet" method="post">
		起：<input name="start" />止：<input name="stop" />示例：2017-06-23
		<button type="submit">确认</button>
	</form>
	病事假：
	<ul>
		<li>总计：${leaveList.size() }</li>
		<c:forEach items="${leaveList }" var="log">
			<li>姓名：${log.worker.name }&nbsp;&nbsp;&nbsp;&nbsp;日期：${log.time }&nbsp;&nbsp;&nbsp;&nbsp;原因：${log.leave }</li>
		</c:forEach>
	</ul>
	旷工：
	<ul>
		<li>总计： ${wdList.size()-count }</li>
		<c:forEach items="${wdList }" var="wd">
			<c:if test="${wd.count!=0 }">
				<li>姓名：${wd.worker.name }&nbsp;&nbsp;&nbsp;&nbsp;天数：${wd.count }</li>
			</c:if>
		</c:forEach>
	</ul>
	迟到早退：
	<ul>
		<li>总计：${lateList.size()+earlyList.size() }</li>
		<c:forEach items="${lateList }" var="late">
			<li>姓名：${late.worker.name }&nbsp;&nbsp;&nbsp;&nbsp;日期：${late.time }&nbsp;&nbsp;&nbsp;&nbsp;类型：${late.leave }</li>
		</c:forEach>
		<c:forEach items="${earlyList }" var="early">
			<li>姓名：${early.worker.name }&nbsp;&nbsp;&nbsp;&nbsp;日期：${early.time }&nbsp;&nbsp;&nbsp;&nbsp;类型：${early.leave }</li>
		</c:forEach>
	</ul>
	加班：
	<ul>
		<li>总计：${overtimeList.size() }</li>
		<c:forEach items="${overtimeList }" var="applet">
			<li>姓名：${applet.worker.name }&nbsp;&nbsp;&nbsp;&nbsp;日期：${applet.time }</li>
		</c:forEach>
	</ul>
	满勤：
	<ul>
		<li>总计：${count }</li>
		<c:forEach items="${wdList }" var="wd">
			<c:if test="${wd.count==0 }">
				<li>姓名：${wd.worker.name }</li>
			</c:if>
		</c:forEach>
	</ul>
</body>
</html>