#include <vector>
#include <list>
#include <string>
#include <iostream>
//#include <iterator>
using namespace std;

//自定义函数 FindTheList，返回l中第id个 list<int> 类型的引用
list<int>& FindTheList(vector<list<int> >& l, int id){
    int temp = l.size();

    if (temp > 0){
        vector<list<int> >::iterator i;
        i = l.begin();
        return *(i + id - 1);
    }
}

int main(){
    int n;  //命令个数
    int id;
    vector<list<int> > a;  //二维动态数组，vector中套用 list<int> 类型
    cin >> n;

    for (int i = 0; i < n; i++){
        string command;  //每行的命令
        cin >> command;

        if (command == "new"){
            cin >> id;
            a.push_back(list<int>());  //vector中压入一个空的 list<int> 类型的元素，即 list<int>()
        }
        else if (command == "add"){
            int num;
            cin >> id >> num;
            list<int>& theid = FindTheList(a, id);
            theid.push_back(num);
            theid.sort();  //将list中的元素按“<”规定的比较方法升序排列
        }
        else if (command == "out"){
            cin >> id;
            list<int>& theid = FindTheList(a, id);
            list<int>::const_iterator ii;
            for (ii = theid.begin(); ii != theid.end(); ii++)
                cout << *ii << " ";
            cout << endl;
        }
        else if (command == "merge"){
            int id1;
            cin >> id >> id1;
            list<int>& theid = FindTheList(a, id);
            list<int>& theid1 = FindTheList(a, id1);
            theid.merge(theid1);
            theid.sort();
        }
        else if (command == "unique"){
            cin >> id;
            list<int>& theid = FindTheList(a, id);
            theid.unique();
        }
    }

    return 0;
}
