package com.hkj.oamanager.servlet;

import java.io.IOException;
import java.sql.Date;
import java.util.Calendar;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.LogBean;
import com.hkj.oamanager.dao.LogDao;

/*
 * 未打卡登记对应服务类
 */
@WebServlet("/MakeUpServlet")
public class MakeUpServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public MakeUpServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(new java.util.Date(System.currentTimeMillis()));
		calendar.add(Calendar.DAY_OF_MONTH, -1);
		LogBean log = new LogBean();
		String name = request.getParameter("name");
		String leave = request.getParameter("leave");
		log.setLeave(leave);
		log.setWorker(name);
		log.setTime(new Date(calendar.getTime().getTime()));
		if (LogDao.add(log)) {
			response.sendRedirect("success.jsp");
		} else {
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
