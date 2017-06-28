package com.hkj.oamanager.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.PartBean;
import com.hkj.oamanager.dao.PartDao;

/*
 * 部门显示对应服务类
 */
@WebServlet("/DisplayPartServlet")
public class DisplayPartServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public DisplayPartServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		List<PartBean> list = PartDao.selectAll();
		request.setAttribute("list", list);
		getServletContext().getRequestDispatcher("/displaypart.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
