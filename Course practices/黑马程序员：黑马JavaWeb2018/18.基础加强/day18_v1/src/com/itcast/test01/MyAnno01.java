package com.itcast.test01;

// 自定义一个注解
public @interface MyAnno01
{
	// 给注解定义一个属性 默认值-1
	public long timeout() default -1;
	
	
	
	
	/*注解的属性不支持自定义的类类型，只支持String, Class, 
	annotation, enumeration are permitted or 1-dimensional arrays thereof*/
	// public TestAnnotation aa();
	public Class c() default java.util.Date.class; // 字节码类型的属性
	public MyAnno02 a();
	public String[] strs();
}
