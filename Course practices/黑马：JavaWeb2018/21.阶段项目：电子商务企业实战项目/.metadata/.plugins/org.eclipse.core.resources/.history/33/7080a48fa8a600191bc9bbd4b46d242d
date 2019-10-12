package com.itmayiedu.mapper;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import com.itmayiedu.entity.UserEntity;

public interface UserMapper
{
	@Select("select * from users where name=#{name}")
	UserEntity findName(@Param("name") String name);
}
