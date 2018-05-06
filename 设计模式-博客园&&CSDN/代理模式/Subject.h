/*
 @Date    : 2018-04-25 09:59:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
一种类型的女人，接口抽象类
 */

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject
{
public:
    Subject() {}
    ~Subject() {}
    virtual void makeEyesWithMan() = 0; // 抛媚眼
    virtual void makeLoveWithMan() = 0; // 呵呵哒

};

#endif // SUBJECT_H

