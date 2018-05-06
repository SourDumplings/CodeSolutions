/*
 @Date    : 2018-04-25 09:58:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
比如西门庆找潘金莲，那潘金莲不好意思答复呀，咋办，找那个王婆做代理。（这个有意思的栗子出自一本电子书《24种设计模式介绍与6大设计原则.pdf》）
　　涉及到的对象如下：
　　main(),西门庆
　　CSubject,接口
　　CWangPo,代理王婆
　　CPanJinLian,实际执行者之一，潘金莲
　　CJiaShi,实际执行者之二，贾氏（书作者的脑洞略大...）
　　说明：代理和实际执行者派生于共同的接口，代理拥有实际执行者的实例。代理的每一个函数（接口的实现函数），直接调用实际执行者的对应接口函数。
　　注意：代理只是简单的装载，然后调用实际执行者的函数。
 */

#include "stdafx.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // call 王婆
    shared_ptr<Wangpo> pWangpo;
    // 西门庆想和潘金莲干些什么，王婆安排
    printf("\n西门庆想和潘金莲干些什么，王婆安排\n");
    pWangpo = make_shared<Wangpo>(make_shared<Panjinlian>());
    pWangpo->makeEyesWithMan();
    pWangpo->makeLoveWithMan();

    // 西门庆想和贾氏搞些事情，王婆安排
    printf("\n西门庆想和贾氏搞些事情，王婆安排\n");
    pWangpo = make_shared<Wangpo>(make_shared<Jiashi>());
    pWangpo->makeEyesWithMan();
    pWangpo->makeLoveWithMan();
    return 0;
}

