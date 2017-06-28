package com.hkj.oamanager.bean;

import java.sql.Date;

import com.hkj.oamanager.dao.WorkerDao;

/*
 * 申请对应实体类
 */
public class AppletBean {

	private int id;
	private String type;
	private WorkerBean worker;
	private Date time = new Date(System.currentTimeMillis());

	public Date getTime() {
		return time;
	}

	public void setTime(Date time) {
		this.time = time;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
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
}
