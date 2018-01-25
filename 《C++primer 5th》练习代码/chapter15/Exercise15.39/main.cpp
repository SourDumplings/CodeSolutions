/*
 @Date    : 2018-01-10 20:11:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p648
 */

#include <iostream>
#include <fstream>
#include "Complex_Query.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    ifstream fin("storyDataFile");
    QueryResult result = q.eval(TextQuery(fin));
    print(cout, result);
    return 0;
}
