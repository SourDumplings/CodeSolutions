/*
 @Date    : 2018-04-24 18:46:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
策略二：求吴国太开绿灯，放行
 */

#ifndef GIVEN_GREEN_LIGHT_H
#define GIVEN_GREEN_LIGHT_H

#include "Strategy.h"

class GivenGreenLight: public Strategy
{
public:
    GivenGreenLight();
    ~GivenGreenLight();
    void operate() override;
};

#endif // GIVEN_GREEN_LIGHT_H


