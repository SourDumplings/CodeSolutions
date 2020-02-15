import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-02-15 10:06:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/combination-sum-ii/
 */

class Solution
{
    private int l;
    private List<List<Integer>> res = new ArrayList<>();
    private LinkedList<Integer> thisList = new LinkedList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target)
    {
        Arrays.sort(candidates);
        l = candidates.length;
        int lastNum = 0;
        for (int i = 0; i < l; i++)
        {
            int thisNum = candidates[i];
            if (target < thisNum)
            {
                break;
            }

            if (i > 0 && lastNum == thisNum)
            {
                continue;
            }
            thisList.add(thisNum);
            backtrack(candidates, target - thisNum, i);
            thisList.removeLast();
            lastNum = thisNum;
        }
        return res;
    }

    private void backtrack(int[] candidates, int target, int index)
    {
        if (target == 0)
        {
            res.add((LinkedList<Integer>) (thisList.clone()));
        }
        else
        {
            int lastNum = 0;
            for (int i = index + 1; i < l; i++)
            {
                int thisNum = candidates[i];
                if (target < thisNum)
                {
                    break;
                }

                if (i > 0 && lastNum == thisNum)
                {
                    continue;
                }
                thisList.add(thisNum);
                backtrack(candidates, target - thisNum, i);
                thisList.removeLast();
                lastNum = thisNum;
            }
        }
    }
}