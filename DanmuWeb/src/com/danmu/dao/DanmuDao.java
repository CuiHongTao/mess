package com.danmu.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import com.danmu.bean.Danmu;
import com.danmu.tools.ConnectionManager;

public class DanmuDao {
	public static boolean operation(String oper, Object o) {
		boolean b = false;
		Connection conn = ConnectionManager.getConnection();
		if (oper.equals("add")) {
			b = add((Danmu) o, conn);
		} else if (oper.equals("delete")) {
			b = delete((Danmu) o, conn);
		}
		// do operation
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return b;
	}

	private static boolean delete(Danmu o, Connection conn) {
		return false;
	}

	private static boolean add(Danmu o, Connection conn) {
		PreparedStatement st = null;
		String sql = "INSERT INTO danmu (userid,time,text) VALUES (?,?,?)";
		try {
			st = conn.prepareStatement(sql);
			st.setInt(1, o.getUserid());
			st.setInt(2, o.getTime());
			st.setString(3, o.getText());
			st.execute();
			return true;
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
}
