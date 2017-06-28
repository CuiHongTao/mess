package com.hkj.oamanager.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Iterator;
import java.util.List;

import com.hkj.oamanager.bean.LogBean;
import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.bean.WorkerDate;
import com.hkj.oamanager.dao.WorkerDao;

public class StatisticsTool {

	public static List<String> fulltime(List<LogBean> logList, String start, String stop, int late) {
		List<String> list = new ArrayList<>();

		return list;
	}

	// 统计迟到列表
	public static List<LogBean> late(List<LogBean> logList) {
		boolean flag = false;
		List<LogBean> list = new ArrayList<>();
		List<LogBean> offSign = new ArrayList<>();
		Iterator<LogBean> it = logList.iterator();
		while (it.hasNext()) {
			LogBean log = it.next();
			if (log.getLeave().equals("下班")) {
				offSign.add(log);
			}
		}
		it = offSign.iterator();
		while (it.hasNext()) {
			LogBean log = it.next();
			Iterator<LogBean> its = logList.iterator();
			while (its.hasNext()) {
				LogBean logs = its.next();
				if (logs.getWorker().equals(log.getWorker()) && logs.getTime().equals(log.getTime())
						&& logs.getLeave().equals("上班")) {
					flag = true;
				}
			}
			if (flag == false) {
				LogBean logn = new LogBean();
				logn.setLeave("迟到");
				logn.setTime(log.getTime());
				logn.setWorker(log.getWorker().getId());
				list.add(logn);
			} else {
				flag = false;
			}
		}
		return list;
	}

	// 统计早退列表
	public static List<LogBean> early(List<LogBean> logList) {
		boolean flag = false;
		List<LogBean> list = new ArrayList<>();
		List<LogBean> offSign = new ArrayList<>();
		Iterator<LogBean> it = logList.iterator();
		while (it.hasNext()) {
			LogBean log = it.next();
			if (log.getLeave().equals("上班")) {
				offSign.add(log);
			}
		}
		it = offSign.iterator();
		while (it.hasNext()) {
			LogBean log = it.next();
			Iterator<LogBean> its = logList.iterator();
			while (its.hasNext()) {
				LogBean logs = its.next();
				if (logs.getWorker().equals(log.getWorker()) && logs.getTime().equals(log.getTime())
						&& logs.getLeave().equals("下班")) {
					flag = true;
				}
			}
			if (flag == false) {
				LogBean logn = new LogBean();
				logn.setLeave("早退");
				logn.setTime(log.getTime());
				logn.setWorker(log.getWorker().getId());
				list.add(logn);
			} else {
				flag = false;
			}
		}
		return list;
	}

	// 计算两个日期之间的天数
	public static int daysBetween(String smdate, String bdate) throws ParseException {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		Calendar cal = Calendar.getInstance();
		cal.setTime(sdf.parse(smdate));
		long time1 = cal.getTimeInMillis();
		cal.setTime(sdf.parse(bdate));
		long time2 = cal.getTimeInMillis();
		long between_days = (time2 - time1) / (1000 * 3600 * 24);

		return Integer.parseInt(String.valueOf(between_days));
	}

	public static List<WorkerDate> absent(int sum, List<LogBean> logList) {
		List<WorkerDate> list = new ArrayList<>();
		List<WorkerBean> workerlist = WorkerDao.selectAll();
		Iterator<WorkerBean> it = workerlist.iterator();
		while (it.hasNext()) {
			int count = 0;
			WorkerBean worker = it.next();
			WorkerDate wd = new WorkerDate();
			wd.setWorker(worker);
			Iterator<LogBean> it2 = logList.iterator();
			while (it2.hasNext()) {
				LogBean log = it2.next();
				if (log.getWorker().equals(worker) && (!log.getLeave().equals("下班"))) {
					count++;
				}
			}
			it2 = late(logList).iterator();
			while (it2.hasNext()) {
				LogBean log = it2.next();
				if (log.getWorker().equals(worker)) {
					count++;
				}
			}
			wd.setCount(sum - count);
			list.add(wd);
		}
		return list;
	}
}
