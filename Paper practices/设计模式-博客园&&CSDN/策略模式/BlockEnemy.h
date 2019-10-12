/*
 @Date    : 2018-04-24 18:51:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
策略三：孙夫人断后，挡住追兵：
 */

#ifndef BLOCK_ENEMY_H
#define BLOCK_ENEMY_H

#include "Strategy.h"

class BlockEnemy: public Strategy
{
public:
    BlockEnemy();
    ~BlockEnemy();

    void operate() override;
};

#endif // BLOCK_ENEMY_H


