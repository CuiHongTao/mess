<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>弹幕网</title>
<script type="text/javascript" for="window" event="onload">
	var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
	xmlDoc.async = "false";
	xmlDoc.load("element.xml");
	var root = xmlDoc.documentElement;
	var nodes = root.childNodes;
	author.innerText = nodes.item(1).text;
</script>
<script type="text/javascript">
	var str1 = [ "", "", "", "", "", "", "", "", "", "", "", "", "", "" ];
	var col = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
</script>
</head>
<body>
		<input type="hidden" id="username" value="false" >
	<%
		boolean flag = true;
		String username = (String) session.getAttribute("username");
		if (username == null) {
			Cookie[] cookies = request.getCookies();
			if (cookies == null) {
	%><div style="position: absolute; top: 30px; left: 1330px; z-index: 2">
		<a href="LogIn.jsp"><font color="blue">登录</font></a>
	</div>
	<%
		flag = false;
			} else {
				for (Cookie c : cookies) {
					if (c.getName().equals("username")) {
						username = c.getValue();
					}
				}
				if (username == null) {
	%><div style="position: absolute; top: 30px; left: 1330px; z-index: 2">
		<a href="LogIn.jsp"><font color="blue">登录</font></a>
	</div>
	<%
		flag = false;
				}
			}
		}
		if (flag) {
	%><div style="position: absolute; top: 30px; left: 1300px; z-index: 2">
		<a href="LogIn.jsp"><font color="blue">重新登录</font></a>
	</div>
	<div style="position: absolute; top: 30px; left: 1200px; z-index: 2">
		<a href="Manage.jsp"><font color="blue">账户管理</font></a>
	</div>
	<div style="position: absolute; top: 30px; left: 1000px; z-index: 2">
		<font color="pink">您好，<%=username%></font>
	</div>
	<script type="text/javascript">
		document.getElementById("username").value = "true";
	</script>
	<%
		session.setAttribute("username", username);
		}
	%>
	<div
		style="position: absolute; top: 0px; left: 0px; width: 1800px; height: 890px; z-index: -1">
		<img src="444.jpg" height="890" width="1800">
	</div>
	<div
		style="position: absolute; top: 0px; left: 0px; width: 400px; z-index: 0; height: 300px;">
		<h3>
			<font color="orange">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;主播简介</font>
		</h3>
		<ul>
			<li><font color="orange">姓名：不拉不拉</font></li>
			<li><font color="orange">性别：不明</font></li>
			<li><font color="orange">年龄：不明</font></li>
			<li><font color="orange">爱好：直播</font></li>
			<li><font color="orange">留言：不拉淘宝店铺倒闭清仓大甩卖了，原价70元，60元，50元的商品，现在统统只要1元钱，是的，只要1元钱。一元钱，你买不了吃亏，一元钱，你买不了上当，走过路过，千万不要错过。</font></li>
		</ul>
	</div>

	<div
		style="position: absolute; top: 300px; width: 400px; background: #0055FF; height: 40px; left: 0px; z-index: 0;">
		<div style="position: absolute; top: -10px; z-index: 1;">
			<h4>
				<font color="#000055">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;贡献榜</font>
			</h4>
		</div>
		<div style="position: absolute; top: -10px; left: 295px; z-index: 1;">
			<h4>
				<font color="#000055">&nbsp;&nbsp;贡献总额</font>
			</h4>
		</div>
	</div>

	<div
		style="position: absolute; top: 340px; left: 0px; width: 400px; height: 70px; z-index: 0;">
		&nbsp;<font color="#EE5500"><b>①</b>&nbsp;不拉大军1 </font><br /> &nbsp;<font
			color="#AA5500"><b>②</b>&nbsp;不拉大军2 </font><br /> &nbsp;<font
			color="#665500"><b>③</b>&nbsp;不拉大军3 </font><br />
	</div>

	<div
		style="position: absolute; top: 340px; left: 305px; width: 400px; height: 70px; z-index: 0;">
		<font color="#EE5500">987500</font><br /> <font color="#AA5500">973400</font><br />
		<font color="#665500">775200</font><br />
	</div>

	<div
		style="position: absolute; top: 410px; width: 400px; background: #0055FF; height: 40px; left: 0px; z-index: 0;">
		<div style="position: absolute; top: -10px; z-index: 1;">
			<h4>
				<font color="#000055">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;现场观众</font>
			</h4>
		</div>
	</div>

	<div
		style="position: absolute; top: 450px; left: 0px; width: 400px; height: 320px; z-index: 0;">
		<script type="text/javascript">
			for (i = 1; i < 15; i++)
				document
						.write("<font color='#665500'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;不拉大军"
								+ i + "</font><br/>");
		</script>
	</div>

	<div
		style="position: absolute; top: 0px; left: 400px; width: 1000px; height: 770px; z-index: 0;">
		<img width="1000" height="770" alt="123" src="222.jpg">
	</div>

	<div
		style="position: absolute; top: -10px; left: 440px; width: 1000px; z-index: 1;">
		<h1>
			<font color="#FF00FF">欢迎来到我的直播间</font>
		</h1>
	</div>

	<div
		style="position: absolute; top: 70px; left: 410px; width: 980px; z-index: 3;">
		<script>
			for (i = 0; i < 14; i++)
				document
						.write("<marquee behavior='scroll' direction='left' scrollamount='10' loop='-1' id='marquee" + i + "'><font color='green' size='6'><b>"
								+ str1[i] + "<b><br><font></marquee>");
			function mar() {
				for (i = 0; i < 13; i++) {
					col[i] = col[i + 1];
					document.getElementById("marquee" + i).innerHTML = "<font size='6' color='#"+col[i]+"'><b>"
							+ str1[i] + "<b><br></font>";
				}
				col[13] = getrandom();
				document.getElementById("marquee" + 13).innerHTML = "<font size='6' color='#"+col[13]+"'><b>"
						+ str1[13] + "<b><br></font>";
			}
			function getrandom() {
				var random;
				var colrandom = "";
				for (i = 0; i < 6; i++) {
					var flag = 0;
					random = Math.random() * 15;
					for (j = 1; j < 10; j++)
						if (random < j) {
							colrandom += String(j - 1);
							var flag = 1;
							break;
						}
					if (flag == 0) {
						if (random < 10)
							colrandom += "A";
						else if (random < 11)
							colrandom += "B";
						else if (random < 12)
							colrandom += "C";
						else if (random < 13)
							colrandom += "D";
						else if (random < 14)
							colrandom += "E";
						else if (random < 15)
							colrandom += "F";
						else
							alert("随机数有误");
					}
				}
				return colrandom;
			}
		</script>
	</div>

	<div
		style="position: absolute; z-index: 1; top: 65px; left: 405px; width: 990px; height: 700px; background: black;"></div>
	<div
		style="position: absolute; z-index: 2; top: 70px; left: 410px; width: 980px; height: 690px;">
		<img width="980" height="690" alt="123" src="111.gif">
	</div>

	<div
		style="position: absolute; top: 0px; width: 400px; background: #0055FF; height: 40px; left: 1400px; z-index: 0;">
		<div style="position: absolute; top: -10px; z-index: 1;">
			<h4>
				<font color="#000055">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;贵宾席</font>
			</h4>
		</div>
	</div>

	<div
		style="position: absolute; top: 40px; left: 1400px; width: 400px; height: 320px; z-index: 0;">
		<script type="text/javascript">
			for (i = 1; i < 16; i++)
				document
						.write("<font color='orange'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;不拉大军"
								+ i + "</font><br/>");
		</script>
	</div>

	<div
		style="position: absolute; top: 360px; width: 400px; background: #0055FF; height: 40px; left: 1400px; z-index: 0;">
		<div style="position: absolute; top: -10px; z-index: 1;">
			<h4>
				<font color="#000055">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;弹幕</font>
			</h4>
		</div>
	</div>

	<div id="danmulishi"
		style="position: absolute; top: 400px; left: 1400px; width: 400px; height: 320px; z-index: 0;">
		<script type="text/javascript">
			function update() {
				if (document.getElementById("username").value == "false") {
					alert("请先登录");
					return;
				}
				var str = document.danmu.input.value;
				if (str == "")
					return;
				for (i = 0; i < 13; i++) {
					str1[i] = str1[i + 1];
				}
				window.open("DanmuUp?danmu="+str);
				str1[13] = str;
				mar();
				output();
				document.danmu.input.value = "";
			}

			function output() {
				var text = "";
				for (i = 0; i < 13; i++)
					text += "<font color = '#"
						+ col[i] + "'>" + str1[i]
							+ "<br></font>"
				text += "<font color = '#"
					+ col[13] + "'>" + str1[13]
						+ "</font>";
				document.getElementById("danmulishi").innerHTML = text;
			}

			function keyDown(e) {
				if (e.keyCode == 13) {
					update();
				}
			}

			output();
		</script>
	</div>

	<div
		style="position: absolute; top: 720px; left: 1400px; width: 400px; height: 50px; z-index: 1;">
		<form action="NewFile.jsp" method="post" name="danmu">
			<br /> <input type="text" size="38" maxlength="50"
				placeholder="请输入弹幕"
				onfocus="javascript:if(this.value=='请输入弹幕')this.value='';"
				name="input" onkeydown="keyDown(event)" id="companyName" /> <input
				type="button" value="发送" onclick="update()" /> <input
				id="hiddenText" type="text" style="display: none" />
		</form>
	</div>

	<div
		style="position: absolute; top: 770px; left: 0px; width: 1800px; height: 120px; z-index: 1; background: white;">
		<img alt="礼物" src="333.jpg" width="1800" height="120">
	</div>
</body>
</html>