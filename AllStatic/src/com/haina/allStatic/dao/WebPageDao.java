package com.haina.allStatic.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.haina.allStatic.bean.WebPageBean;
import com.haina.allStatic.util.ConnectionManager;

public class WebPageDao {

	public boolean add(WebPageBean t) {
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from webpage where name=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, t.getName());
			rs = st.executeQuery();
			if (!rs.next()) {
				sql = "INSERT INTO webpage (name,location1,location2,type,subtitle) VALUES (?,?,?,?,?)";
				st.close();
				st = conn.prepareStatement(sql);
				st.setString(1, t.getName());
				st.setString(2, t.getLocation1());
				st.setString(3, t.getLocation2());
				st.setString(4, t.getType());
				st.setString(5, t.getSubTitle());
				st.execute();
				return true;
			} else {
				if (t.getLocation1() == null) {
					sql = "update webpage set location2=? where name=?";
				} else {
					sql = "update webpage set location1=? where name=?";
				}
				st.close();
				st = conn.prepareStatement(sql);
				if (t.getLocation1() == null) {
					st.setString(1, t.getLocation2());
				} else {
					st.setString(1, t.getLocation1());
				}
				st.setString(2, t.getName());
				st.execute();
				return true;
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
		return false;
	}

	public int getMaxId() {
		int id = 0;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		try {
			String sql = "select MAX(id) from webpage";
			st = conn.prepareStatement(sql);
			rs = st.executeQuery();
			if (rs.next()) {
				id = rs.getInt(1);
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
		return id;
	}

	public int getIdByName(String name) {
		int id = -1;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select id from webpage where name=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, name);
			rs = st.executeQuery();
			if (rs.next()) {
				id = rs.getInt(1);
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
		return id;
	}

	public List<WebPageBean> selectAll(int currentPage, int pageSize) {
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		List<WebPageBean> list = new ArrayList<>();
		String sql = "select id,name,location1,location2,type,hits,subtitle from webpage  limit ?,?";
		PreparedStatement ps = null;
		try {
			ps = conn.prepareStatement(sql);
			ps.setInt(1, (currentPage - 1) * pageSize);
			ps.setInt(2, pageSize);
			rs = ps.executeQuery();
			while (rs.next()) {
				WebPageBean s = new WebPageBean();
				s.setId(rs.getInt(1));
				s.setName(rs.getString(2));
				s.setLocation1(rs.getString(3));
				s.setLocation2(rs.getString(4));
				s.setType(rs.getString(5));
				s.setHits(rs.getInt(6));
				s.setSubTitle(rs.getString(7));
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

	public int getItemSize() {
		int totalItem = 0;
		Connection conn = ConnectionManager.getConnection();
		Statement st = null;
		ResultSet rs = null;
		try {
			st = conn.createStatement();
			String sql = "select count(*)from webpage";
			rs = st.executeQuery(sql);
			if (rs.next()) {
				totalItem = rs.getInt(1);
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
		return totalItem;
	}
}
