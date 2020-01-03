package com.cz.hello.spring.transaction.service;

import com.cz.hello.spring.transaction.domain.TbContent;
import com.cz.hello.spring.transaction.domain.TbContentCategory;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/2 22:21
 */
public interface TbContentCategoryService
{
    void save(TbContentCategory tbContentCategory, TbContent tbContent);
}