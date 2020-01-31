import java.util.Stack;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-06 11:15:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * 
 * 对于左右子列的边界即是乱序元素本应所在的最小及最大位置
 * 左边界：从左到右扫描数组，维持一个升序栈，直到找到一个比栈顶元素小的元素。
 * 此时将元素出栈，直到栈顶元素小于该元素，那么该元素应该在有序序列的位置就是该元素目前的位置
 * 减去出栈的元素数。找出在有序序列位置最左的乱序元素的位置即为左边界。
 * 右边界同理。
 * 可以让栈维持元素下标而不是元素本身来减少代码量。
 * 
 * 时间和空间复杂度都为O(n)
 */

class Solution
{
    public int findUnsortedSubarray(int[] nums)
    {
        Stack<Integer> S = new Stack<>();
        int n = nums.length;
        int f = n, l = -1;
        for (int i = 0; i < n; i++)
        {
            while (!S.isEmpty() && nums[i] < nums[S.peek()])
            {
                f = Math.min(f, S.pop());
            }
            S.push(i);
        }
        S.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!S.isEmpty() && nums[i] > nums[S.peek()])
            {
                l = Math.max(l, S.pop());
            }
            S.push(i);
        }
        return f < l ? l - f + 1 : 0;
    }
}
