package com.itheima.test;

import java.io.File;
import java.util.List;

import org.dom4j.Document;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;

public class MainTest
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		try
		{
			// 1.创建sax读取对象
			SAXReader reader = new SAXReader();
			
			// 2.指定新的解析xml源
			Document document = reader.read(new File("src/xml/stus.xml"));
			
			// 3.得到元素
			// 得到根元素
			Element rootElement = document.getRootElement();
			// 获取根元素下面的子元素
			System.out.println(rootElement.element("stu").element("age").getText());
			// 获取根元素下面所有子元素
			List<Element> elements = rootElement.elements();
			for (Element element : elements)
			{
				// 获取stu元素下面的name元素
				String name = element.element("name").getText();
				String age = element.element("age").getText();
				String address = element.element("address").getText();
				
				
				System.out.println("name: " + name + ", age: " + age +
						", address: " + address);
			}
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
	}

}
