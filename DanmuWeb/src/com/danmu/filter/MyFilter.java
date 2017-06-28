package com.danmu.filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.danmu.dao.UserDao;

public class MyFilter implements Filter {

	@Override
	public void doFilter(ServletRequest arg0, ServletResponse arg1, FilterChain arg2)
			throws IOException, ServletException {
		HttpServletResponse response = (HttpServletResponse) arg1;
		HttpServletRequest request = (HttpServletRequest) arg0;
		HttpSession session = request.getSession(true);
		String username = (String) session.getAttribute("username");
		if (username == null || username.equals("")) {
			arg2.doFilter(arg0, arg1);
			return;
		} else if (!UserDao.operation("checkByName", username)) {
			session.setAttribute("username", "");
			response.sendRedirect("LogIn.jsp");
			return;
		}
		arg2.doFilter(arg0, arg1);
	}

}
