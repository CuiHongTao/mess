package com.hkj.oamanager.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.hkj.oamanager.bean.PartBean;
import com.hkj.oamanager.bean.WorkerBean;
import com.hkj.oamanager.util.ConnectionManager;

/*
 * 员工表对应查询
 */
public class WorkerDao {

	// 通过名字进行查找
	public static WorkerBean selectByName(String workerName) {
		WorkerBean worker = null;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from worker where name=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, workerName);
			rs = st.executeQuery();
			if (rs.next()) {
				worker = new WorkerBean();
				worker.setId(rs.getInt(1));
				worker.setName(rs.getString(2));
				worker.setPart(rs.getInt(3));
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
				st.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return worker;
	}
	
	// 通过id进行查找
		public static WorkerBean selectById(int workerId) {
			WorkerBean worker = null;
			Connection conn = ConnectionManager.getConnection();
			PreparedStatement st = null;
			ResultSet rs = null;
			String sql = "select * from worker where id=?";
			try {
				st = conn.prepareStatement(sql);
				st.setInt(1, workerId);
				rs = st.executeQuery();
				if (rs.next()) {
					worker = new WorkerBean();
					worker.setId(rs.getInt(1));
					worker.setName(rs.getString(2));
					worker.setPart(rs.getInt(3));
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
					st.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
			return worker;
		}

	// 添加操作
	public static boolean add(WorkerBean worker) {
		boolean flag = false;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from worker where name=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, worker.getName());
			rs = st.executeQuery();
			if (!rs.next()) {
				sql = "INSERT INTO worker (name,partid) VALUES (?,?)";
				st.close();
				st = conn.prepareStatement(sql);
				st.setString(1, worker.getName());
				st.setInt(2, worker.getPart().getId());
				st.execute();
				flag = true;
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
				st.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return flag;
	}

	// 通过名字删除人员
	public static boolean deleteByName(WorkerBean worker) {
		if (selectByName(worker.getName()) == null) {
			return false;
		}
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		String sql = "DELETE FROM worker WHERE name = ?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, worker.getName());
			st.execute();
			return true;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}

	// 查找所有员工
	public static List<WorkerBean> selectAll() {
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		List<WorkerBean> list = new ArrayList<>();
		String sql = "select * from worker";
		Statement st = null;
		try {
			st = conn.createStatement();
			rs = st.executeQuery(sql);
			while (rs.next()) {
				WorkerBean s = new WorkerBean();
				s.setId(rs.getInt(1));
				s.setName(rs.getString(2));
				s.setPart(rs.getInt(3));
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
				st.close();
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

	// 通过部门查找
	public static List<WorkerBean> selectByPart(PartBean part) {
		List<WorkerBean> list = new ArrayList<>();
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		String sql = "select * from worker where partid=?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setInt(1, part.getId());
			rs = ps.executeQuery();
			while (rs.next()) {
				WorkerBean s = new WorkerBean();
				s.setId(rs.getInt(1));
				s.setName(rs.getString(2));
				s.setPart(rs.getInt(3));
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

	// 修改员工信息
	public static boolean update(WorkerBean old, WorkerBean news) {
		boolean flag = false;
		if ((news.getName() == null || news.getName().equals("")) && news.getPart() == null) {
			return false;
		}
		if (news.getName() == null || news.getName().equals("")) {
			news.setName(old.getName());
		}
		if (news.getPart() == null) {
			news.setPart(old.getPart());
		}
		if (old.getName() != null || !old.getName().equals("")) {
			Connection conn = ConnectionManager.getConnection();
			PreparedStatement st = null;
			String sql = "update worker set name=?,partid=? where name=?";
			try {
				st = conn.prepareStatement(sql);
				st.setString(1, news.getName());
				st.setInt(2, news.getPart().getId());
				st.setString(3, old.getName());
				st.execute();
				flag = true;
			} catch (SQLException e) {
				e.printStackTrace();
			} finally {
				try {
					st.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return flag;
	}
}
