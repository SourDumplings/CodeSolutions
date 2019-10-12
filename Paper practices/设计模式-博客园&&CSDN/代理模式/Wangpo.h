/*
 @Date    : 2018-04-25 10:11:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
代理类，王婆
 */

#ifndef WANGPO_H
#define WANGPO_H

#include "Subject.h"
#include <memory>

using namespace std;

class Wangpo: public Subject
{
public:
    Wangpo(shared_ptr<Subject> pSubject);
    ~Wangpo();
    void makeEyesWithMan() override;
    void makeLoveWithMan() override;
private:
    shared_ptr<Subject> m_pSubject;
};

#endif // WANGPO_H


