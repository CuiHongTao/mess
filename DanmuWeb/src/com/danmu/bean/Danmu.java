package com.danmu.bean;

/**
 * 与弹幕对应的实体类
 */
public class Danmu {

	/**主键*/
	private int userid;
	/**发送时间*/
	private int time;
	/**弹幕内容*/
	private String text;

	public Danmu(){}
	public Danmu(int userid,int time,String text){
		this.userid = userid;
		this.time = time;
		this.text = text;
	}
	public int getUserid() {
		return userid;
	}

	public void setUserid(int userid) {
		this.userid = userid;
	}

	public int getTime() {
		return time;
	}

	public void setTime(int time) {
		this.time = time;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

}
