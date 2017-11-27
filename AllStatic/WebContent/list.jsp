<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE HTML>
<html>
<head>
<title>新闻列表</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="keywords" content="" />
<script type="applijewelleryion/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>
<link href="css/bootstrap.css" rel='stylesheet' type='text/css' />
<link href="css/style.css" rel='stylesheet' type='text/css' />
<script src="js/jquery-1.11.1.min.js"></script>
<script src="js/bootstrap.min.js"></script>
<script language="javascript" type="text/javascript">
	function text() {
		var text = document.getElementById("text").value;
		if (text)
			window.navigate("NewsListServlet?currentPage=" + text);
	}
</script>
</head>
<body>
	<c:if test="${empty userlist }">
		<c:redirect url="NewsListServlet?currentpage=${param.currentPage }" />
	</c:if>
	<!--start-main-->
	<div class="header-bottom">
		<div class="container">
			<div class="logo">
				<h1>
					<a href="index.html">天海广纳</a>
				</h1>
				<p>
					<label class="of"></label>新闻列表<label class="on"></label>
				</p>
			</div>
		</div>
	</div>
	<!-- banner -->

	<div class="banner-1"></div>

	<!-- technology-left -->
	<div class="technology">
		<div class="container">
			<div class="col-md-9 technology-left">
				<div class="blog">

					<h2 class="w3">新闻列表</h2>
					<div class="blog-grids1">
						<c:forEach items="${userlist}" var="s">
							<div class="col-md-6 blog-grid">
								<div class="blog-grid-left1">
									<img src="images/t1.jpg" alt=" " class="img-responsive">
								</div>
								<div class="blog-grid-right1">
									<a href="*">${s.name }</a>
									<p>${s.subTitle }</p>
								</div>
								<div class="clearfix"></div>
								<div class="more m1">
									<a class="btn effect6" href="${s.location1 }">使用模板1阅读</a> <a
										class="btn effect6" href="${s.location2 }">使用模板2阅读</a>
								</div>
							</div>
						</c:forEach>
						<div class="clearfix"></div>
					</div>
					<nav class="paging">
						<ul class="pagination pagination-lg">
							<a href="NewsListServlet?currentPage=${currentPage-1 }">上一页</a>
							<a href="NewsListServlet?currentPage=${currentPage-1 }"><c:if
									test="${currentPage>1 }">${currentPage-1 }</c:if> </a>
							<font> ${currentPage }</font>
							<a href="NewsListServlet?currentPage=${currentPage+1 }"> <c:if
									test="${currentPage<totalPage }">${currentPage+1 }</c:if>
							</a>
							<a href="NewsListServlet?currentPage=${currentPage+1 }">下一页</a>
							&nbsp;&nbsp;共
							<span>${totalPage }</span>页 到第
							<input type="text" name="text" id="text" size=1
								onkeyup="this.value=this.value.replace(/\D/g,'')"
								onkeypress="if(event.keyCode==13) {text();return false;}" />页
						</ul>
					</nav>

				</div>
			</div>
			<!-- technology-right -->
			<div class="col-md-3 technology-right">


				<div class="blo-top1">

					<div class="tech-btm">
						<div class="search-1">
							<form action="#" method="post">
								<input type="search" name="Search" value="Search"
									onfocus="this.value = '';"
									onblur="if (this.value == '') {this.value = 'Search';}"
									required=""> <input type="submit" value=" ">
							</form>
						</div>
						<h4>其他新闻</h4>
						<div class="blog-grids">
							<div class="blog-grid-left">
								<a href="*"><img src="images/t2.jpg" class="img-responsive"
									alt=""></a>
							</div>
							<div class="blog-grid-right">

								<h5>
									<a href="*">Pellentesque dui Maecenas male</a>
								</h5>
							</div>
							<div class="clearfix"></div>
						</div>
						<div class="blog-grids">
							<div class="blog-grid-left">
								<a href="*"><img src="images/m2.jpg" class="img-responsive"
									alt=""></a>
							</div>
							<div class="blog-grid-right">

								<h5>
									<a href="*">Pellentesque dui Maecenas male</a>
								</h5>
							</div>
							<div class="clearfix"></div>
						</div>
						<div class="blog-grids">
							<div class="blog-grid-left">
								<a href="*"><img src="images/f2.jpg" class="img-responsive"
									alt=""></a>
							</div>
							<div class="blog-grid-right">

								<h5>
									<a href="*">Pellentesque dui Maecenas male</a>
								</h5>
							</div>
							<div class="clearfix"></div>
						</div>
						<div class="blog-grids">
							<div class="blog-grid-left">
								<a href="*"><img src="images/t3.jpg" class="img-responsive"
									alt=""></a>
							</div>
							<div class="blog-grid-right">

								<h5>
									<a href="*">Pellentesque dui Maecenas male</a>
								</h5>
							</div>
							<div class="clearfix"></div>
						</div>
						<div class="blog-grids">
							<div class="blog-grid-left">
								<a href="*"><img src="images/m3.jpg" class="img-responsive"
									alt=""></a>
							</div>
							<div class="blog-grid-right">

								<h5>
									<a href="*">Pellentesque dui Maecenas male</a>
								</h5>
							</div>
							<div class="clearfix"></div>
						</div>
						<div class="insta">
							<h4>Instagram</h4>
							<ul>

								<li><a href="*"><img src="images/t1.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/m1.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/f1.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/m2.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/f2.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/t2.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/f3.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/t3.jpg"
										class="img-responsive" alt=""></a></li>
								<li><a href="*"><img src="images/m3.jpg"
										class="img-responsive" alt=""></a></li>
							</ul>
						</div>

						<p>Lorem ipsum ex vix illud nonummy, novum tation et his. At
							vix scripta patrioque scribentur, at pro</p>
					</div>



				</div>


			</div>
			<div class="clearfix"></div>
			<!-- technology-right -->
		</div>
	</div>
</body>
</html>




