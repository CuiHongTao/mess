package com.danmu.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.danmu.bean.User;
import com.danmu.tools.ConnectionManager;

public class UserDao {

	public static boolean operation(String oper, Object o) {
		boolean b = false;
		Connection conn = ConnectionManager.getConnection();
		if (oper.equals("add")) {
			b = add((User) o, conn);
		} else if (oper.equals("check")) {
			b = check((User) o, conn);
		} else if (oper.equals("delete")) {
			b = delete((User) o, conn);
		} else if (oper.equals("checkByName")) {
			b = checkByName((String) o, conn);
		} else if (oper.equals("change")) {
			b = change((User) o, conn);
		} else if (oper.equals("shijian")){}
		// do operation
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return b;
	}

	private static boolean delete(User u, Connection conn) {
		if (check(u, conn)) {
			PreparedStatement st = null;
			String sql = "DELETE FROM users WHERE username = ?";
			try {
				st = conn.prepareStatement(sql);
				st.setString(1, u.getUsername());
				st.execute();
				return true;
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return false;
	}

	private static boolean add(User u, Connection conn) {
		PreparedStatement st = null;
		ResultSet rs = null;
		String sql = "select * from users where username=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, u.getUsername());
			rs = st.executeQuery();
			if (!rs.next()) {
				sql = "INSERT INTO users (username,password) VALUES (?,?)";
				st.close();
				st = conn.prepareStatement(sql);
				st.setString(1, u.getUsername());
				st.setString(2, u.getPassword());
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
		}
		return false;
	}

	private static boolean check(User u, Connection conn) {
		PreparedStatement st = null;
		String sql = "select * from users where username=? and password=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, u.getUsername());
			st.setString(2, u.getPassword());
			ResultSet rs = st.executeQuery();
			if (rs.next()) {
				return true;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				st.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return false;
	}

	private static boolean checkByName(String u, Connection conn) {
		PreparedStatement st = null;
		String sql = "select * from users where username=?";
		try {
			st = conn.prepareStatement(sql);
			st.setString(1, u);
			ResultSet rs = st.executeQuery();
			if (rs.next()) {
				return true;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				st.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return false;
	}

	private static boolean change(User u, Connection conn) {
		if (checkByName(u.getUsername(), conn)) {
			PreparedStatement st = null;
			String sql = "update users set password=? where username=?";
			try {
				st = conn.prepareStatement(sql);
				st.setString(1, u.getPassword());
				st.setString(2, u.getUsername());
				st.execute();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					st.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		return false;
	}
}
