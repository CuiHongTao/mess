package com.danmu.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.danmu.bean.Danmu;

public class DanmuUp extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public DanmuUp() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String text = request.getParameter("danmu");
		HttpSession session = request.getSession(true);
		String username = (String) session.getAttribute("username");
		response.getWriter().write("<script>window.close();</script>");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
