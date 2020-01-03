package com.cz.hello.spring.transaction.domain;

import java.util.Date;
import lombok.Data;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-spring-transaction
 * @date 2020/1/2 22:00
 */
@Data
public class TbContentCategory
{
    private Long id;
    private String name;
    private Integer status;
    private Integer sortOrder;
    private Boolean isParent;
    private Date created;
    private Date updated;
    private TbContentCategory parent;
}