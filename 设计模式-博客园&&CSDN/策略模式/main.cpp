/*
 @Date    : 2018-04-24 18:37:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
策略模式

赵云护送刘备去娶亲，诸葛亮给了赵云三个锦囊妙计

main(),赵云
　　CContext,锦囊
　　CStrategy,策略抽象类
　　CBackDoor,策略之一
　　CGivenGreenLight,策略之二
　　CBlockEnemy,策略之三
　　说明：一个策略放到一个锦囊里。当用的时候，找到这个锦囊，从锦囊里拿出策略来使用。
　　注意：锦囊只是简单的装载和调用策略，锦囊里没有逻辑。策略会有更大的自主权，运行更多的逻辑。
 */

#include "stdafx.h"

using namespace std;

int main(int argc, char const *argv[])
{
    std::shared_ptr<Context> pContext; // 锦囊

    printf("\n----------刚刚到吴国的时候拆第一个----------\n");
    pContext = make_shared<Context>(make_shared<BackDoor>()); // 第一个锦囊
    pContext->openAndOperate();

    printf("\n---------刘备乐不思蜀了，拆第二个了----------\n");
    pContext = make_shared<Context>(make_shared<GivenGreenLight>());
    pContext->openAndOperate();

    printf("\n----------孙权的小兵追了，咋办？拆第三个----------\n");
    pContext = make_shared<Context>(make_shared<BlockEnemy>());
    pContext->openAndOperate();

    return 0;
}

