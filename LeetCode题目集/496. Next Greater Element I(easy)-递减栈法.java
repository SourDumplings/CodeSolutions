import java.util.Hashtable;
import java.util.Map;
import java.util.Stack;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 15:48:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/next-greater-element-i/
 * 
 * 比如序列 5 4 3 2 1 6
 * 那么 5 4 3 2 1这5个元素的下一个比他们大的元素就是6
 * 于是我们用栈来维持一个递减序列，栈顶元素是栈中元素的最大值，
 * 每当遇到比栈顶元素大的元素时，弹栈并记录这些元素的下一个比他们大的元素就是遇到的这个元素
 */

class Solution
{
    public int[] nextGreaterElement(int[] nums1, int[] nums2)
    {
        Map<Integer, Integer> map = new Hashtable<>();
        Stack<Integer> S = new Stack<>();
        int l1 = nums1.length;
        int l2 = nums2.length;
        for (int i = 0; i < l2; i++)
        {
            while (!S.empty() && nums2[i] > S.peek())
            {
                map.put(S.pop(), nums2[i]);
            }
            S.push(nums2[i]);
        }
        for (int i = 0; i < l1; i++)
        {
            nums1[i] = map.getOrDefault(nums1[i], -1);
        }
        return nums1;
    }
}