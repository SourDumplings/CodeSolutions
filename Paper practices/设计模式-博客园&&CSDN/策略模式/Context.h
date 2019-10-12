/*
 @Date    : 2018-04-24 18:55:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
锦囊
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include "Strategy.h"
#include <memory>

class Context
{
public:
    Context(std::shared_ptr<Strategy>);
    ~Context();
    void openAndOperate();
private:
    std::shared_ptr<Strategy> m_pStrategy;
};

#endif // CONTEXT_H


