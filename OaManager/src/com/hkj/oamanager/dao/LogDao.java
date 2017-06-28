package com.hkj.oamanager.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.hkj.oamanager.bean.LogBean;
import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.util.ConnectionManager;

/*
 * 打卡表对应查询
 */
public class LogDao {

	// 对打卡表进行添加
	public static boolean add(LogBean log) {
		boolean flag = false;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement ps = null;
		String sql = "INSERT INTO log (workerid,time,leavess) VALUES (?,?,?)";
		try {
			ps = conn.prepareStatement(sql);
			ps.setInt(1, log.getWorker().getId());
			ps.setDate(2, log.getTime());
			ps.setString(3, log.getLeave());
			ps.execute();
			flag = true;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return flag;
	}

	// 按请假进行查找
	public static List<LogBean> selectByLeave(String start, String stop) {
		List<LogBean> list = new ArrayList<>();
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		String sql = "SELECT * FROM log WHERE leavess!='上班' and leavess!='下班' and time BETWEEN ? AND ?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, start);
			ps.setString(2, stop);
			rs = ps.executeQuery();
			while (rs.next()) {
				LogBean s = new LogBean();
				s.setId(rs.getInt(1));
				s.setWorker(rs.getInt(2));
				s.setTime(rs.getDate(3));
				s.setLeave(rs.getString(4));
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

	// 按日期查找
	public static List<LogBean> selectByDay(String start, String stop) {
		List<LogBean> list = new ArrayList<>();
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		String sql = "SELECT * FROM log WHERE time BETWEEN ? AND ?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, start);
			ps.setString(2, stop);
			rs = ps.executeQuery();
			while (rs.next()) {
				LogBean s = new LogBean();
				s.setId(rs.getInt(1));
				s.setWorker(rs.getInt(2));
				s.setTime(rs.getDate(3));
				s.setLeave(rs.getString(4));
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

	// 按月份查找
	public static List<LogBean> selectByMonth(String year, String month) {
		List<LogBean> list = new ArrayList<>();
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		String sql = "SELECT * FROM log WHERE year(time)=? AND month(time)=?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, year);
			ps.setString(2, month);
			rs = ps.executeQuery();
			while (rs.next()) {
				LogBean s = new LogBean();
				s.setId(rs.getInt(1));
				s.setWorker(rs.getInt(2));
				s.setTime(rs.getDate(3));
				s.setLeave(rs.getString(4));
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

	// 按员工查找
	public static List<LogBean> selectByWorker(WorkerBean worker) {
		List<LogBean> list = new ArrayList<>();
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		String sql = "SELECT * FROM log WHERE workerid=?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setInt(1, worker.getId());
			rs = ps.executeQuery();
			while (rs.next()) {
				LogBean s = new LogBean();
				s.setId(rs.getInt(1));
				s.setWorker(rs.getInt(2));
				s.setTime(rs.getDate(3));
				s.setLeave(rs.getString(4));
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
