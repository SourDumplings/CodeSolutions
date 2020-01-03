package com.cz.hello.spring.transaction.service.test;

import com.cz.hello.spring.transaction.domain.TbContent;
import com.cz.hello.spring.transaction.domain.TbContentCategory;
import com.cz.hello.spring.transaction.service.TbContentCategoryService;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.annotation.Rollback;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/3 14:52
 */
@Transactional
@Rollback
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration({"classpath:spring-context.xml", "classpath:spring-context-druid.xml",
    "classpath:spring-context-mybatis.xml"})
public class MyTest
{
    @Autowired
    private TbContentCategoryService tbContentCategoryService;

    @Test
    public void testTransaction()
    {
        TbContentCategory tbContentCategory = new TbContentCategory();
        tbContentCategory.setId(1L);
        tbContentCategory.setName("测试分类");

        TbContent tbContent = new TbContent();
        tbContent.setTitle("测试内容");
        tbContent.setTbContentCategory(tbContentCategory);

        tbContentCategoryService.save(tbContentCategory, tbContent);
    }
}
