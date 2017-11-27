package com.haina.allStatic.servlet;

import java.io.IOException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.haina.allStatic.bean.PageBean;
import com.haina.allStatic.bean.WebPageBean;
import com.haina.allStatic.dao.WebPageDao;
import com.haina.allStatic.staticize.StaticizeTool;

@WebServlet("/AddNewsServlet")
public class AddNewsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public AddNewsServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		// 获取页面信息
		String name = request.getParameter("title");
		String author = request.getParameter("author");
		String type = request.getParameter("type");
		String subTitle = request.getParameter("subtitle");
		String context = request.getParameter("textarea");
		// 获取应有的id
		String id = String.valueOf(StaticizeTool.getId(name));
		// 获取当前时间
		Date time = new Date(System.currentTimeMillis());

		// 创建页面对应数据库类
		WebPageBean webPageBean = new WebPageBean();
		webPageBean.setName(name);
		webPageBean.setType(type);
		webPageBean.setSubTitle(subTitle);

		StaticizeTool staticizeTool = new StaticizeTool();
		// 创建页面类和物理页面
		PageBean pageBean = new PageBean();
		pageBean.setAuthor(author);
		pageBean.setContext(context);
		pageBean.setSubTitle(subTitle);
		pageBean.setTime(time);
		pageBean.setTitle(name);
		String pagePath = null;
		if (request.getParameter("submit").equals("提交1模板")) {
			pageBean.setLocation(id + "A.html");
			pagePath = staticizeTool.StaticizePageA(pageBean);
			webPageBean.setLocation1(pagePath);
		} else {
			pageBean.setLocation(id + "B.html");
			pagePath = staticizeTool.StaticizePageB(pageBean);
			webPageBean.setLocation2(pagePath);
		}

		//存入数据库
		WebPageDao webPageDao = new WebPageDao();
		webPageDao.add(webPageBean);
		getServletContext().getRequestDispatcher("/NewsListServlet").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
