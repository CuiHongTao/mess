package com.haina.allStatic.staticize;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import com.haina.allStatic.bean.PageBean;
import com.haina.allStatic.dao.WebPageDao;

public class StaticizeTool {

	// 静态页面模板和生成路径
	private static String PATH = "D:\\workspace\\AllStatic\\WebContent";

	public static int getId(String name) {
		WebPageDao webPageDao = new WebPageDao();
		int id = webPageDao.getIdByName(name);
		if (id < 0) {
			id = webPageDao.getMaxId() + 1;
		}
		return id;
	}

	public String StaticizePageA(PageBean pageBean) {
		String pagePath = PATH + "\\" + pageBean.getLocation();
		this.changeContent(PATH + "\\新闻内容模板1.html", pagePath, "新闻标题", pageBean.getTitle());
		this.changeContent(pagePath, PATH + "\\temp.html", "新闻副标题", pageBean.getSubTitle());
		this.changeContent(PATH + "\\temp.html", pagePath, "时间", pageBean.getTime().toString());
		this.changeContent(pagePath, PATH + "\\temp.html", "作者", pageBean.getAuthor());
		this.changeContent(PATH + "\\temp.html", pagePath, "具体内容", pageBean.getContext());
		return pagePath;
	}

	public String StaticizePageB(PageBean pageBean) {
		String pagePath = PATH + "\\" + pageBean.getLocation();
		this.changeContent(PATH + "\\新闻内容模板1.html", pagePath, "新闻标题", pageBean.getTitle());
		this.changeContent(pagePath, PATH + "\\temp.html", "新闻副标题", pageBean.getSubTitle());
		this.changeContent(PATH + "\\temp.html", pagePath, "时间", pageBean.getTime().toString());
		this.changeContent(pagePath, PATH + "\\temp.html", "作者", pageBean.getAuthor());
		this.changeContent(PATH + "\\temp.html", pagePath, "具体内容", pageBean.getContext());
		return pagePath;
	}

	private void changeContent(String filePath, String savePath, String befor, String then) {
		// filePath 要读取的文件 savePath 要写入的文件
		BufferedReader br = null;
		BufferedWriter bw = null;
		String content = "";
		try {
			// 以下读取和写入都转成UTF-8 防止乱码
			br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath), "UTF-8"));
			bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(savePath), "UTF-8"));
			StringBuffer str = new StringBuffer(then);
			String line;
			while ((line = br.readLine()) != null && (line != "")) {
				content = line + br.readLine();
				bw.write(content.replaceAll(befor, str.toString()).replace("null", ""));
			}
			bw.flush();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
				if (bw != null)
					bw.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
}
