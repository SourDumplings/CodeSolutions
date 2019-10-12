/*
 @Date    : 2018-05-01 11:16:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
小红试卷类
 */

#ifndef XIAO_HONG_TEST_PAPER_H
#define XIAO_HONG_TEST_PAPER_H

#include "TestPaper.h"
#include <iostream>

using namespace std;

class XiaoHongTestPaper: public TestPaper
{
public:
    void StudentName()
    {
        cout << "姓名：小红" << endl;
    }
    void AnswerOne()
    {
        cout << "答：相信X,相信国家，明年一定降下来。" << endl << endl;
    }
    void AnswerTwo()
    {
        cout << "答：新闻联播是我最喜欢的节目啊。" << endl << endl;
    }
};

#endif // XIAO_HONG_TEST_PAPER_H


