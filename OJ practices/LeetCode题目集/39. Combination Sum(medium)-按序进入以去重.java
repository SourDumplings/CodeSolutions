import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-02-13 22:17:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/combination-sum/
 */

class Solution
{
    private LinkedList<Integer> thisList = new LinkedList<>();
    private int thisSum = 0;
    private List<List<Integer>> res = new ArrayList<>();
    private int l;

    public List<List<Integer>> combinationSum(int[] candidates, int target)
    {
        l = candidates.length;
        Arrays.sort(candidates);
        for (int i = 0; i < l; i++)
        {
            backtrack(candidates, target, i);
        }
        return res;
    }

    private void backtrack(int[] candidates, int target, int start)
    {
        int thisNum = candidates[start];
        thisSum += thisNum;
        thisList.add(thisNum);
        if (thisSum == target)
        {
            res.add((LinkedList<Integer>) (thisList.clone()));
        }
        else if (thisSum < target)
        {
            for (int i = start; i < l; i++)
            {
                backtrack(candidates, target, i);
            }
        }
        thisSum -= thisNum;
        thisList.removeLast();
    }
}