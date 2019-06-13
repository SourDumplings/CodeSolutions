package cn.itcast.store.test;

import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.beanutils.ConvertUtils;
import org.apache.commons.beanutils.converters.DateConverter;
import org.junit.Test;

import cn.itcast.store.domain.User;

public class TestBeanUtils
{
	@Test
	public void test01() throws IllegalAccessException, InvocationTargetException
	{
		// 模拟request.getParameterMap()
		Map<String, String[]> map = new HashMap<String, String[]>();
		map.put("username", new String[]{"tom"});
		map.put("password", new String[]{"1234"});
		
		User user = new User();
		BeanUtils.populate(user, map);
		
		System.out.println(user);
	}
	
	@Test
	public void test02() throws IllegalAccessException, InvocationTargetException
	{
		// 模拟request.getParameterMap()
		Map<String, String[]> map = new HashMap<String, String[]>();
		map.put("username", new String[]{"tom"});
		map.put("password", new String[]{"1234"});
		map.put("birthday", new String[]{"1992-3-3"});
		
		User user = new User();
		
		// 1.创建时间类型的转换器
		DateConverter dt = new DateConverter();
		// 2.设置转换格式
		dt.setPattern("yyyy-MM-dd");
		// 3.注册转换器
		ConvertUtils.register(dt, java.util.Date.class);
		
		BeanUtils.populate(user, map);
		System.out.println(user);
	}
}
