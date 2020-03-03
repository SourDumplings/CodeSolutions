import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-03-03 11:21:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/permutations-ii/
 */

class Solution
{
    private int l;
    private List<List<Integer>> res;
    private ArrayList<Integer> thisList;
    private boolean[] visited;

    public List<List<Integer>> permuteUnique(int[] nums)
    {
        res = new ArrayList<>();
        l = nums.length;
        thisList = new ArrayList<>();
        visited = new boolean[l];

        Arrays.fill(visited, false);
        Arrays.sort(nums);

        int last = -1;
        for (int i = 0; i < l; i++)
        {
            if (i == 0 || last != nums[i])
            {
                backtrack(nums, i);
            }
            last = nums[i];
        }
        return res;
    }

    private void backtrack(int[] nums, int i)
    {
        thisList.add(nums[i]);
        visited[i] = true;

        if (thisList.size() == l)
        {
            res.add(new ArrayList<>(thisList));
        }
        else
        {
            int last = -1;
            boolean first = true;
            for (int j = 0; j < l; j++)
            {
                if (!visited[j] && (first || nums[j] != last))
                {
                    backtrack(nums, j);
                    last = nums[j];
                    first = false;
                }
            }
        }

        thisList.remove(thisList.size() - 1);
        visited[i] = false;
    }
}