/*
 @Date    : 2018-05-01 11:07:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
假如你是一个老师，现在你要给你的学生出一份期末考试试卷。你班上有几十个学生，你将考虑如何为设计考试卷。
  经分析显然学生的试卷大部分内容都是一致的，唯一不一致的是姓名和答案。
  老师设计好试卷，只需要把试卷交个学生填写答案即可。学生不需要把题目照抄一份。
  即题目是抽象基类的，答案是各自子类的
所以我们需要把试卷抽象成基类，并且给学生留下填写答案以及姓名的地方。
 */

#include "stdafx.h"

using namespace std;

int main(int argc, char const *argv[])
{
    XiaoHongTestPaper paper1;
    paper1.DoTestPaper();

    XiaoZhangTestPaper paper2;
    paper2.DoTestPaper();

    system("pause");
    return 0;
}

