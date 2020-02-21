import java.util.Stack;

/*
 * @Author: SourDumplings
 * @Date: 2020-02-21 19:13:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/trapping-rain-water/
 * 
 * 使用栈记录元素的索引，统计“凹陷”的信息
 * 如果当前的元素比栈顶的元素的高度小则入栈，说明当前元素被栈顶元素界定
 * 否则如果如果当前的元素比栈顶的元素的高度大，弹栈，
 * 说明当前元素和栈顶的前一个比栈顶元素大的元素界定栈顶元素
 * 
 * 每个条形快最多访问两次，时间复杂度 O(n)，空间复杂度 O(n)
 */

class Solution
{
    public int trap(int[] height)
    {
        Stack<Integer> stack = new Stack<>();
        int n = height.length;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            while (!stack.isEmpty() && height[stack.peek()] < height[i])
            {
                int top = stack.peek();
                stack.pop();
                if (stack.isEmpty())
                {
                    break;
                }
                else
                {
                    int left = stack.peek();
                    res += (Math.min(height[left], height[i]) - height[top]) * (i - left - 1);
                }
            }
            stack.push(i);
        }
        return res;
    }
}