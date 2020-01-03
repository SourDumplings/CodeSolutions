package com.cz.hello.spring.transaction.service.impl;

import com.cz.hello.spring.transaction.dao.TbContentCategoryDao;
import com.cz.hello.spring.transaction.domain.TbContent;
import com.cz.hello.spring.transaction.domain.TbContentCategory;
import com.cz.hello.spring.transaction.service.TbContentCategoryService;
import com.cz.hello.spring.transaction.service.TbContentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/2 22:22
 */
@Transactional(readOnly = true)
@Service
public class TbContentCategoryServiceImpl implements TbContentCategoryService
{

    @Autowired
    private TbContentCategoryDao tbContentCategoryDao;

    @Autowired
    private TbContentService tbContentService;

    @Transactional(readOnly = false)
    public void save(TbContentCategory tbContentCategory, TbContent tbContent)
    {
        tbContentCategoryDao.insert(tbContentCategory);

        // if (true)
        // {
        //     throw new RuntimeException();
        // }

        tbContentService.save(tbContent);
    }
}
