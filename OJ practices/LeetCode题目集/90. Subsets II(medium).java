/*
 * @Author: SourDumplings
 * @Date: 2020-08-19 18:31:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/subsets-ii/
 */

class Solution
{
    private Set<List<Integer>> res = new HashSet<>();
    private Set<List<Integer>> setOfEqualLength = new HashSet<>();
    private List<Integer> thisL = new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums)
    {
        int l = nums.length;
        for (int i = 0; i <= l; i++)
        {
            getSubSets(nums, i);
        }
        return new ArrayList<>(res);
    }

    private void getSubSets(int[] nums, int n)
    {
        if (n == 0)
        {
            res.add(new ArrayList<>());
            return;
        }
        int l = nums.length;
        for (int i = 0; i < l; i++)
        {
            setOfEqualLength.clear();
            dfs(nums, i, n - 1);
            for (List<Integer> subSet : setOfEqualLength)
            {
                List<Integer> list = new ArrayList<>(subSet);
                Collections.sort(list);
                res.add(list);
            }
        }
    }

    private void dfs(int[] nums, int index, int size)
    {
        thisL.add(nums[index]);
        if (size == 0)
        {
            setOfEqualLength.add(new ArrayList<>(thisL));
        }
        else
        {
            int l = nums.length;
            for (int i = index + 1; i < l; i++)
            {
                dfs(nums, i, size - 1);
            }
        }
        thisL.remove(thisL.size() - 1);
    }
}