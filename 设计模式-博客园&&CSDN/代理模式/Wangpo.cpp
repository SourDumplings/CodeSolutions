/*
 @Date    : 2018-04-25 10:13:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
王婆代理类的实现
 */

#include "Wangpo.h"

Wangpo::Wangpo(shared_ptr<Subject> pSubject):
    m_pSubject(pSubject) {}

Wangpo::~Wangpo() {}

void Wangpo::makeEyesWithMan()
{
    m_pSubject->makeEyesWithMan();
    return;
}

void Wangpo::makeLoveWithMan()
{
    m_pSubject->makeLoveWithMan();
    return;
}


