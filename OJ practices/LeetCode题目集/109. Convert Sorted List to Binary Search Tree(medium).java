/*
 * @Author: SourDumplings
 * @Date: 2020-09-06 16:41:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 */

class Solution
{
    public TreeNode sortedListToBST(ListNode head)
    {
        List<Integer> nums = new ArrayList<>();
        ListNode p = head;
        while (p != null)
        {
            nums.add(p.val);
            p = p.next;
        }
        return buildTree(nums, 0, nums.size());
    }

    private TreeNode buildTree(List<Integer> nums, int b, int e)
    {
        if (b >= e)
        {
            return null;
        }
        int mi = (b + e) / 2;
        TreeNode left = buildTree(nums, b, mi);
        TreeNode right = buildTree(nums, mi + 1, e);
        return new TreeNode(nums.get(mi), left, right);
    }
}

