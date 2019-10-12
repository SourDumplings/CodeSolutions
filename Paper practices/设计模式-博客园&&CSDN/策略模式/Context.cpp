/*
 @Date    : 2018-04-24 19:02:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
锦囊
 */

#include <iostream>
#include <memory>
#include "Context.h"

using namespace std;

Context::Context(shared_ptr<Strategy> pStrategy):
    m_pStrategy(pStrategy) {}

Context::~Context() {}

void Context::openAndOperate()
{
    m_pStrategy->operate();
    return;
}
