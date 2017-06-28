package com.hkj.oamanager.servlet;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.PartBean;
import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.dao.PartDao;
import com.hkj.oamanager.dao.WorkerDao;

/*
 * 查询人员对应服务类
 */
@WebServlet("/SelectWorkerServlet")
public class SelectWorkerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public SelectWorkerServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		List<WorkerBean> list = new ArrayList<>();
		String condition = request.getParameter("condition");
		if (condition == null || condition.equals("")) {
			list = WorkerDao.selectAll();
			request.setAttribute("list", list);
			getServletContext().getRequestDispatcher("/selectworker.jsp").forward(request, response);
		} else {
			WorkerBean worker = WorkerDao.selectByName(condition);
			if (worker != null){
				list.add(worker);
			}
			PartBean part = PartDao.selectByName(condition);
			if (part != null){
				list.addAll(WorkerDao.selectByPart(part));
			}
			System.out.println(1);
			request.setAttribute("list", list);
			getServletContext().getRequestDispatcher("/selectworker.jsp").forward(request, response);
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
