package com.hkj.oamanager.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.hkj.oamanager.bean.PartBean;
import com.hkj.oamanager.util.ConnectionManager;

/*
 * 部门表对应查询
 */
public class PartDao {

	// 通过名字进行查找并返回
	public static PartBean selectByName(String partName) {
		PartBean part = null;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from part where name=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, partName);
			rs = st.executeQuery();
			if (rs.next()) {
				part = new PartBean();
				part.setId(rs.getInt(1));
				part.setName(rs.getString(2));
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
		return part;
	}

	// 通过id进行查找并返回
	public static PartBean selectById(int partId) {
		PartBean part = null;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from part where id=?";
		try {
			st = conn.prepareStatement(sql);
			st.setInt(1, partId);
			rs = st.executeQuery();
			if (rs.next()) {
				part = new PartBean();
				part.setId(rs.getInt(1));
				part.setName(rs.getString(2));
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
		return part;
	}

	// 进行添加操作
	public static boolean add(PartBean part) {
		boolean flag = false;
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from part where name=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, part.getName());
			rs = st.executeQuery();
			if (!rs.next()) {
				sql = "INSERT INTO part (name) VALUES (?)";
				st.close();
				st = conn.prepareStatement(sql);
				st.setString(1, part.getName());
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

	// 通过名字删除部门
	public static boolean deleteByName(PartBean part) {
		if (selectByName(part.getName()) == null) {
			return false;
		}
		Connection conn = ConnectionManager.getConnection();
		PreparedStatement st = null;
		String sql = "DELETE FROM part WHERE name = ?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, part.getName());
			st.execute();
			return true;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}

	// 显示全部部门
	public static List<PartBean> selectAll() {
		Connection conn = ConnectionManager.getConnection();
		ResultSet rs = null;
		List<PartBean> list = new ArrayList<>();
		String sql = "select * from part";
		Statement st = null;
		try {
			st = conn.createStatement();
			rs = st.executeQuery(sql);
			while (rs.next()) {
				PartBean s = new PartBean();
				s.setId(rs.getInt(1));
				s.setName(rs.getString(2));
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
	
	//修改部门信息
	public static Boolean update (PartBean old,PartBean news){
		boolean flag = false;
		if (news.getName() == null || news.getName().equals("")){
			return false;
		}
		if (selectByName(old.getName()) != null) {
			Connection conn = ConnectionManager.getConnection();
			PreparedStatement st = null;
			String sql = "update part set name=? where name=?";
			try {
				st = conn.prepareStatement(sql);
				st.setString(1, news.getName());
				st.setString(2, old.getName());
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
