/*
 @Date    : 2018-05-01 11:10:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
试卷抽象类
 */

#ifndef TEST_PAPER_H
#define TEST_PAPER_H

#include <iostream>

using namespace std;

class TestPaper
{
public:
    void DoTestPaper()
    {
        StudentName();
        TestTitleOne();
        TestTitleTwo();
    };

    void TestTitleOne()
    {
        cout << "题目一：X国的房价会降下来么？" << endl;
        AnswerOne();
    }

    void TestTitleTwo()
    {
        cout << "题目二：说说你的新闻联播的看法？" << endl;
        AnswerTwo();
    }

    virtual void AnswerOne() = 0;
    virtual void AnswerTwo() = 0;
    virtual void StudentName() = 0;
    virtual ~TestPaper() {}
};

#endif // TEST_PAPER_H


