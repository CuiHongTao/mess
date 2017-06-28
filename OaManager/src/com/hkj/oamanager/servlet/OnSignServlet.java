package com.hkj.oamanager.servlet;

import java.io.IOException;
import java.sql.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.LogBean;
import com.hkj.oamanager.dao.LogDao;

/*
 * 上班打卡对应服务类
 */
@WebServlet("/OnSignServlet")
public class OnSignServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public OnSignServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		LogBean log = new LogBean();
		String name = request.getParameter("name");
		log.setTime(new Date(System.currentTimeMillis()));
		log.setWorker(name);
		log.setLeave("上班");
		if (LogDao.add(log)) {
			response.sendRedirect("success.jsp");
		} else {
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
