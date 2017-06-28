package com.hkj.oamanager.bean;

import com.hkj.oamanager.dao.PartDao;

/*
 * Ա����Ӧʵ����
 */
public class WorkerBean {

	private int id;
	private String name;
	private PartBean part;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public PartBean getPart() {
		return part;
	}

	public void setPart(String partName) {
		this.part = PartDao.selectByName(partName);
	}

	public void setPart(int partId) {
		this.part = PartDao.selectById(partId);
	}

	public void setPart(PartBean part) {
		this.part = part;
	}

	public boolean equals(WorkerBean worker) {
		return worker.getId() == id;
	}
}
