package com.itheima.dao;

import java.sql.SQLException;
import java.util.List;

import com.itheima.domain.WordBean;

public interface WordsDao
{
	/**   
	 * @Title: findWords   
	 * @Description: TODO(这里用一句话描述这个方法的作用)   
	 * @param: @param word
	 * @param: @return
	 * @param: @throws SQLException      
	 * @return: WordBean      
	 * @throws   
	 */  
	List<WordBean> findWords(String word) throws SQLException;
}
