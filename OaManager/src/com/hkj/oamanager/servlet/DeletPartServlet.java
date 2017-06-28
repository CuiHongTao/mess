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
 * ����ɾ����Ӧ������
 */
@WebServlet("/DeletPartServlet")
public class DeletPartServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public DeletPartServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request. setCharacterEncoding("UTF-8");
		String name = request.getParameter("name");
		PartBean part = new PartBean();
		part.setName(name);
		if (PartDao.deleteByName(part)){
			response.sendRedirect("success.jsp");
		}else{
			response.sendRedirect("defeated.jsp");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
