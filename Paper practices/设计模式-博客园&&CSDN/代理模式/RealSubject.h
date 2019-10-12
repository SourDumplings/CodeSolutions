/*
 @Date    : 2018-04-25 10:01:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
潘金莲和贾氏，真实主题类
 */

#ifndef REAL_SUBJECT_H
#define REAL_SUBJECT_H

#include "Subject.h"

class Panjinlian: public Subject
{
public:
    Panjinlian();
    ~Panjinlian();
    void makeEyesWithMan() override;
    void makeLoveWithMan() override;
};

class Jiashi: public Subject
{
public:
    Jiashi();
    ~Jiashi();
    void makeEyesWithMan() override;
    void makeLoveWithMan() override;
};

#endif // REAL_SUBJECT_H


