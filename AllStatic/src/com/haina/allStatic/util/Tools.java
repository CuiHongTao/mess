package com.haina.allStatic.util;

import com.haina.allStatic.dao.WebPageDao;

public class Tools {
	private Tools(){}
	public static int getTotalPage(int pageSize){
		int totalItem = new WebPageDao().getItemSize();
		return totalItem % pageSize == 0 ? totalItem / pageSize : totalItem / pageSize + 1;
	}
}
