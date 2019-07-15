package com.itmayiedu.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.itmayiedu.entity.UserEntity;

public interface UserRepository extends JpaRepository<UserEntity, Integer>
{
	
}
