package com.hkj.oamanager.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.dao.PartDao;
import com.hkj.oamanager.dao.WorkerDao;

/*
 * 添加人员对应服务类
 */
@WebServlet("/AddWorkerServlet")
public class AddWorkerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public AddWorkerServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		String name = request.getParameter("name");
		String part = request.getParameter("part");
		if (PartDao.selectByName(part)==null){
			response.sendRedirect("defeated.jsp");
			return;
		}
		WorkerBean worker = new WorkerBean();
		worker.setName(name);
		worker.setPart(part);
		if(WorkerDao.add(worker)){
			response.sendRedirect("success.jsp");
		}else{
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
