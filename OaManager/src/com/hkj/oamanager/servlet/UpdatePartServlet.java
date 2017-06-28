package com.hkj.oamanager.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.PartBean;
import com.hkj.oamanager.dao.PartDao;

/*
 * 部门修改对应服务类
 */
@WebServlet("/UpdatePartServlet")
public class UpdatePartServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public UpdatePartServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		String oldname = request.getParameter("old");
		String newname = request.getParameter("new");
		PartBean old = new PartBean();
		PartBean news = new PartBean();
		old.setName(oldname);
		news.setName(newname);
		if (PartDao.update(old, news)) {
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
