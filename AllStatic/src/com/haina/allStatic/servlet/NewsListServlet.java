package com.haina.allStatic.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.haina.allStatic.bean.WebPageBean;
import com.haina.allStatic.dao.WebPageDao;
import com.haina.allStatic.util.Tools;

@WebServlet("/NewsListServlet")
public class NewsListServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public NewsListServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		int pageSize = 4;
		int totalPage = 0;
		int currentPage = 0;
		WebPageDao s = new WebPageDao();
		totalPage = Tools.getTotalPage(pageSize);
		String r = request.getParameter("currentPage");
		if (r == null) {
			currentPage = 1;
		} else {
			currentPage = Integer.parseInt(r);
			if (currentPage <= 0) {
				currentPage = 1;
			} else if (currentPage > totalPage) {
				currentPage = totalPage;
			}
		}
		List<WebPageBean> list = s.selectAll(currentPage, pageSize);
		request.setAttribute("userlist", list);
		request.setAttribute("currentPage", currentPage);
		request.setAttribute("totalPage", totalPage);
		System.out.println("111");
		getServletContext().getRequestDispatcher("/list.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
