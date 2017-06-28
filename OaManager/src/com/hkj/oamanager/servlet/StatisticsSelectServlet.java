package com.hkj.oamanager.servlet;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.LogBean;
import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.dao.LogDao;
import com.hkj.oamanager.dao.WorkerDao;

/*
 * 出勤统计查询对应服务类
 */
@WebServlet("/StatisticsSelectServlet")
public class StatisticsSelectServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public StatisticsSelectServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		String condition = request.getParameter("condition");
		if (condition == null || condition.equals("")) {
			response.sendRedirect("defeated.jsp");
			return;
		}
		String type = request.getParameter("type");
		if (type == null || type.equals("")) {
			response.sendRedirect("defeated.jsp");
			return;
		}
		List<LogBean> list = new ArrayList<>();
		switch (type) {
		case "day":
			String day = condition;
			list = LogDao.selectByDay(day, day);
			break;
		case "month":
			String year = condition.substring(0, 4);
			String month = condition.substring(5);
			list = LogDao.selectByMonth(year, month);
			break;
		case "name":
			String name = condition;
			WorkerBean worker = WorkerDao.selectByName(name);
			list = LogDao.selectByWorker(worker);
		}
		if (list.isEmpty()) {
			response.sendRedirect("defeated.jsp");
			return;
		}
		request.setAttribute("list", list);
		getServletContext().getRequestDispatcher("/statisticsselect.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
