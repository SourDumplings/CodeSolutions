package cn.itcast.service;

import java.sql.SQLException;
import java.util.List;

import cn.itcast.dao.ProductDao;
import cn.itcast.utils.PageModel;

public class ProductService
{

	public PageModel findProduct(int curNum) throws SQLException
	{
		//1_创建PageModel对象 目的:计算分页参数
		ProductDao ProductDao=new ProductDao();
		int totalRecords=ProductDao.findToralRecords();
		PageModel pm=new PageModel(curNum,5,totalRecords);
		//2_关联数据  select * from product limit  ? , ?
		List list=ProductDao.findProducts(pm.getStartIndex(),pm.getPageSize());
		pm.setList(list);
		//3_关联url
		pm.setUrl("ProductServlet");
		
		return pm;
	}

}
