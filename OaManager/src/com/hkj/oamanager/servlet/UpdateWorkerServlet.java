package com.hkj.oamanager.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.dao.WorkerDao;

/*
 * 修改人员对应服务类
 */
@WebServlet("/UpdateWorkerServlet")
public class UpdateWorkerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public UpdateWorkerServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		WorkerBean old = WorkerDao.selectByName(request.getParameter("oldname"));
		WorkerBean news = new WorkerBean();
		news.setName(request.getParameter("newname"));
		news.setPart(request.getParameter("newpart"));
		if (WorkerDao.update(old, news)) {
			response.sendRedirect("success.jsp");
		} else {
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
