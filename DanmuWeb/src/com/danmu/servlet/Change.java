package com.danmu.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.danmu.bean.User;
import com.danmu.dao.UserDao;

public class Change extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public Change() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String oldpassword = request.getParameter("oldpassword");
		String newpassword = request.getParameter("newpassword");
		String surepassword = request.getParameter("surepassword");
		if (oldpassword == null||oldpassword.equals("")){
			response.sendRedirect("Change.jsp?error=2");return;
		}else if (newpassword == null||newpassword.equals("")){
			response.sendRedirect("Change.jsp?error=3");return;
		}else if (!newpassword.equals(surepassword)){
			response.sendRedirect("Change.jsp?error=5");return;
		}else{
			HttpSession session = request.getSession(true);
			String username = (String) session.getAttribute("username");
			User user = new User(username,oldpassword);
			if (!UserDao.operation("check", user)){
				response.sendRedirect("Change.jsp?error=1");
				return;
			}else{
				if (oldpassword.equals(newpassword)){
					response.sendRedirect("Change.jsp?error=4");
					return;
				}
				User newuser = new User(username,newpassword);
				UserDao.operation("change", newuser);
				response.sendRedirect("Manage.jsp");
			}
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
