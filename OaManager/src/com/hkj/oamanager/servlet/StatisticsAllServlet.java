package com.hkj.oamanager.servlet;

import java.io.IOException;
import java.text.ParseException;
import java.util.Iterator;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.hkj.oamanager.bean.AppletBean;
import com.hkj.oamanager.bean.LogBean;
import com.hkj.oamanager.bean.WorkerDate;
import com.hkj.oamanager.dao.AppletDao;
import com.hkj.oamanager.dao.LogDao;
import com.hkj.oamanager.util.StatisticsTool;

/*
 * 出勤统计对应服务类
 */
@WebServlet("/StatisticsAllServlet")
public class StatisticsAllServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public StatisticsAllServlet() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		int count = 0;
		request.setCharacterEncoding("UTF-8");
		String start = request.getParameter("start");
		String stop = request.getParameter("stop");
		int dayBetween = 0;
		 try {
			dayBetween = StatisticsTool.daysBetween(start, stop)+1;
		} catch (ParseException e) {
			e.printStackTrace();
			response.sendRedirect("defeated.jsp");
		}
		List<LogBean> logList = LogDao.selectByDay(start, stop);
		List<LogBean> lateList = StatisticsTool.late(logList);
		List<LogBean> earlyList = StatisticsTool.early(logList);
		List<LogBean> leaveList = LogDao.selectByLeave(start, stop);
		List<AppletBean> overtimeList = AppletDao.selectByOvertime(start, stop);
		List<WorkerDate> wdList = StatisticsTool.absent(dayBetween, logList);
		Iterator<WorkerDate> it = wdList.iterator();
		while (it.hasNext()){
			if (it.next().getCount()==0){
				count++;
			}
		}
		request.setAttribute("leaveList", leaveList);
		request.setAttribute("overtimeList", overtimeList);
		request.setAttribute("lateList", lateList);
		request.setAttribute("earlyList", earlyList);
		request.setAttribute("wdList", wdList);
		request.setAttribute("count", count);
		getServletContext().getRequestDispatcher("/statisticsall.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

	

}
