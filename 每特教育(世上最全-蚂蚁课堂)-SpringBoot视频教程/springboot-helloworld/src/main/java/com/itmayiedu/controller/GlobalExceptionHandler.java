package com.itmayiedu.controller;

import java.util.HashMap;
import java.util.Map;

import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;

/**   
 * @ClassName  GlobalExceptionHandler   
 * @Description TODO(全局捕获异常)   
 * @author SourDumplings
 * @date   2019年7月14日 上午11:04:22   
 *     
 * @PL https://github.com/SourDumplings
 */ 
@ControllerAdvice
public class GlobalExceptionHandler
{
	@ExceptionHandler(RuntimeException.class)
	@ResponseBody // 拦截返回是json结果
	public Map<String, Object> exceptionHandler()
	{
		HashMap<String, Object> result = new HashMap<String, Object>();
		result.put("code", "500");
		result.put("msg", "亲，系统错误，请稍后重试");
		return result;
	}
}
