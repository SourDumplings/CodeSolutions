/*
 @Date    : 2018-01-10 16:23:26
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p645
运行结果：
WordQuery constructor
Query constructor on string
WordQuery constructor
Query constructor on string
WordQuery constructor
Query constructor on string
BinaryQuery constructor
AndQuery constructor
Query constructor on Query_base
BinaryQuery constructor
OrQuery constructor
Query constructor on Query_base
 */

#include <iostream>
#include <string>
#include <memory>
#include "Complex_Query.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // Query q = Query("fiery");
    Query q = Query("fiery") & Query("bird") | Query("wind");
    return 0;
}
