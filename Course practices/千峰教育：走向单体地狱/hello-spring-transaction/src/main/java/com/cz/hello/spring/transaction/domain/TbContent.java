package com.cz.hello.spring.transaction.domain;

import java.util.Date;
import lombok.Data;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/2 22:15
 */
@Data
public class TbContent
{
    private Long id;
    private String title;
    private String subTitle;
    private String titleDesc;
    private String url;
    private String pic;
    private String pic2;
    private String content;
    private Date created;
    private Date updated;
    private TbContentCategory tbContentCategory;
}
