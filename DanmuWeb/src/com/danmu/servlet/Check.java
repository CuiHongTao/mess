package com.danmu.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.danmu.bean.User;
import com.danmu.dao.UserDao;

public class Check extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public Check() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String box = request.getParameter("box");
		User user = new User(username, password);
		if (UserDao.operation("check", user)) {
			if (box == "on") {
				Cookie cookie = new Cookie("username", username);
				cookie.setMaxAge(14 * 20 * 60 * 60);
				response.addCookie(cookie);
				Cookie cookie2 = new Cookie("password", password);
				cookie2.setMaxAge(14 * 20 * 60 * 60);
				response.addCookie(cookie2);
			}
			HttpSession session = request.getSession(true);
			session.setAttribute("username", username);
			response.sendRedirect("NewFile.jsp");
		} else {
			response.sendRedirect("LogIn.jsp?error=1");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
