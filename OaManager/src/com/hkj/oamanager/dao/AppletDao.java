package com.hkj.oamanager.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.hkj.oamanager.bean.AppletBean;
import com.hkj.oamanager.util.ConnectionManager;

/*
 * 申请表对应查询
 */
public class AppletDao {

	public static boolean add (AppletBean applet){
		boolean flag = false;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement ps = null;
		String sql = "insert into applet (type,workerid,time) values (?,?,?)";
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, applet.getType());
			ps.setInt(2, applet.getWorker().getId());
			ps.setDate(3, applet.getTime());
			ps.execute();
			flag = true;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return flag;
	}
	
	public static List<AppletBean> selectByOvertime (String start, String stop){
		List<AppletBean> list = new ArrayList<>();
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		String sql = "SELECT * FROM applet WHERE type='加班' and time BETWEEN ? AND ?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, start);
			ps.setString(2, stop);
			rs = ps.executeQuery();
			while (rs.next()) {
				AppletBean s = new AppletBean();
				s.setId(rs.getInt(1));
				s.setType(rs.getString(2));
				s.setWorker(rs.getInt(3));
				s.setTime(rs.getDate(4));
				list.add(s);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			try {
				ps.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return list;
	}
}
