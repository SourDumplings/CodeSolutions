package com.itheima.test;

import java.io.File;
import java.util.List;

import org.dom4j.Document;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;

public class XPathTest
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
			// 要想使用XPath还要添加支持的jar，获得的只返回第一个
			Element nameElement = (Element)rootElement.selectSingleNode("//name");
			System.out.println(nameElement.getText());
			System.out.println("--------------------");
			// 获取文档中所有name元素
			List<Element> selectNodes = rootElement.selectNodes("//name");
			for (Element element : selectNodes)
			{
				// 获取stu元素下面的name元素
				String name = element.getText();
				
				System.out.println("name: " + name);
			}
		}
		catch (Exception e)
		{
			// TODO: handle exception
			e.printStackTrace();
		}
	}

}
