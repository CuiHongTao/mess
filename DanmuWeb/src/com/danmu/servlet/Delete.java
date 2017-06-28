package com.danmu.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.danmu.bean.User;
import com.danmu.dao.UserDao;

public class Delete extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public Delete() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession(true);
		String username = (String) session.getAttribute("username");
		String password = request.getParameter("deltext");
		User user = new User(username,password);
		if (UserDao.operation("delete", user)){
			response.sendRedirect("LogIn.jsp");
		}else{
			response.sendRedirect("Delete.jsp?error=1");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
