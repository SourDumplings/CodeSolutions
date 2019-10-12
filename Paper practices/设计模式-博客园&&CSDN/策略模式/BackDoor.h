/*
 @Date    : 2018-04-24 18:41:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
策略一：初到吴国
 */

#ifndef BACK_DOOR_H
#define BACK_DOOR_H

#include "Strategy.h"

class BackDoor: public Strategy
{
public:
    BackDoor();
    ~BackDoor();
    void operate() override;
};

#endif // BACK_DOOR_H


