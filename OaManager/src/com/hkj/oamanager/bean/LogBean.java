package com.hkj.oamanager.bean;

import java.sql.Date;

import com.hkj.oamanager.dao.WorkerDao;

/*
 * 打卡信息对应实体类
 */
public class LogBean {

	private int id;
	private WorkerBean worker;
	private Date time = new Date(System.currentTimeMillis());
	private String leave;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public WorkerBean getWorker() {
		return worker;
	}

	public void setWorker(String workerName) {
		this.worker = WorkerDao.selectByName(workerName);
	}

	public void setWorker(int workerId) {
		this.worker = WorkerDao.selectById(workerId);
	}
	
	public Date getTime() {
		return time;
	}

	public void setTime(Date time) {
		this.time = time;
	}

	public String getLeave() {
		return leave;
	}

	public void setLeave(String leave) {
		this.leave = leave;
	}

}
