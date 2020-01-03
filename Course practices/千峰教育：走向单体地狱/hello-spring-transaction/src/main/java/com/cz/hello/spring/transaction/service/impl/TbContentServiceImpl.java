package com.cz.hello.spring.transaction.service.impl;

import com.cz.hello.spring.transaction.dao.TbContentDao;
import com.cz.hello.spring.transaction.domain.TbContent;
import com.cz.hello.spring.transaction.service.TbContentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/2 22:24
 */
@Service
public class TbContentServiceImpl implements TbContentService
{

    @Autowired
    private TbContentDao tbContentDao;

    public void save(TbContent tbContent)
    {
        tbContentDao.insert(tbContent);
    }
}
