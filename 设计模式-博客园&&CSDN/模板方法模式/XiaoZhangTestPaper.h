/*
 @Date    : 2018-05-02 10:20:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
小张的试卷
 */

#ifndef XIAO_ZHANG_TEST_PAPER_H
#define XIAO_ZHANG_TEST_PAPER_H

#include "TestPaper.h"

class XiaoZhangTestPaper: public TestPaper
{
public:
    void StudentName()
    {
        cout << "姓名：小张" << endl;
    }
    void AnswerOne()
    {
        cout << "答：呵呵，还是去做你的X国梦吧。" << endl << endl;
    }
    void AnswerTwo()
    {
        cout << "答：我很幸福" << endl << endl;
    }
};

#endif // XIAO_ZHANG_TEST_PAPER_H

