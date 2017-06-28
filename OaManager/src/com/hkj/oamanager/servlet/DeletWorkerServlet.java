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
 * 删除人员对应服务类
 */
@WebServlet("/DeletWorkerServlet")
public class DeletWorkerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public DeletWorkerServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		String name = request.getParameter("name");
		WorkerBean worker = new WorkerBean();
		worker.setName(name);
		if (WorkerDao.deleteByName(worker)){
			response.sendRedirect("success.jsp");
		}else{
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
