import java.util.HashMap;
import java.util.Map;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-17 22:04:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/employee-importance/
 */

/*
// Employee info
class Employee {
   // It's the unique id of each node;
   // unique id of this employee
   public int id;
   // the importance value of this employee
   public int importance;
   // the id of direct subordinates
   public List<Integer> subordinates;
};
*/
class Solution
{
    private int res;

    public int getImportance(List<Employee> employees, int id)
    {
        res = 0;
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee e : employees)
        {
            map.put(e.id, e);
        }
        calcImportance(map, id);
        return res;
    }

    private void calcImportance(Map<Integer, Employee> map, int id)
    {
        Employee e = map.get(id);
        res += e.importance;
        for (int i : e.subordinates)
        {
            calcImportance(map, i);
        }
    }
}