package com.danmu.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.danmu.bean.User;
import com.danmu.dao.UserDao;

public class Register extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public Register() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String p = request.getParameter("password");
		String p2 = request.getParameter("password2");
		String u = request.getParameter("username");
		if (u == null) {
			response.sendRedirect("Register.jsp?error=3");
		} else if (p == null || p2 == null) {
			response.sendRedirect("Register.jsp?error=4");
		} else if (!p.equals(p2)) {
			response.sendRedirect("Register.jsp?error=2");
		} else {
			User user = new User(u, p);
			if (UserDao.operation("add", user)) {
				HttpSession session = request.getSession(true);
				session.setAttribute("username", u);
				response.sendRedirect("NewFile.jsp");
			} else {
				response.sendRedirect("Register.jsp?error=1");
			}
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
