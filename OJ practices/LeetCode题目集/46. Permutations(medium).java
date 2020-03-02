import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-03-02 10:33:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/permutations/
 */

class Solution
{
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> thisList = new ArrayList<>();
    private boolean[] visited;
    private int l;

    public List<List<Integer>> permute(int[] nums)
    {
        l = nums.length;
        visited = new boolean[l];
        Arrays.fill(visited, false);
        for (int i = 0; i < l; i++)
        {
            backtrack(nums, i);
        }
        return res;
    }

    private void backtrack(int[] nums, int i)
    {
        visited[i] = true;
        thisList.add(nums[i]);

        if (thisList.size() == l)
        {
            res.add(new ArrayList<>(thisList));
        }
        else
        {
            for (int j = 0; j < l; j++)
            {
                if (!visited[j])
                {
                    backtrack(nums, j);
                }
            }
        }
        thisList.remove(thisList.size() - 1);
        visited[i] = false;
    }

}