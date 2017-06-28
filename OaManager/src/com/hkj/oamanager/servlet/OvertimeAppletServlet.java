package com.hkj.oamanager.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.AppletBean;
import com.hkj.oamanager.dao.AppletDao;

/*
 * 加班申请对应服务类
 */
@WebServlet("/OvertimeAppletServlet")
public class OvertimeAppletServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public OvertimeAppletServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		String name = request.getParameter("name");
		AppletBean applet = new AppletBean();
		applet.setType("加班");
		applet.setWorker(name);
		if (AppletDao.add(applet)){
			response.sendRedirect("success.jsp");
		} else {
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
