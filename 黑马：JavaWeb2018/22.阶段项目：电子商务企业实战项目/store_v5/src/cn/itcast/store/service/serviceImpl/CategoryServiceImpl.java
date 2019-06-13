package cn.itcast.store.service.serviceImpl;

import java.util.List;

import cn.itcast.store.dao.daoImpl.CategoryDaoImpl;
import cn.itcast.store.domain.Category;
import cn.itcast.store.service.CategoryService;

public class CategoryServiceImpl implements CategoryService
{

	public List<Category> getAllCats() throws Exception
	{
		// TODO Auto-generated method stub
		CategoryDaoImpl categoryDao = new CategoryDaoImpl();
		return categoryDao.getAllCats();
	}

}
