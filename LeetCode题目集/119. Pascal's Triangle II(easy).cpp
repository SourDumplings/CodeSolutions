/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/pascals-triangle-ii/
 * @Date: 2019-03-11 11:47:19
 */

class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        ++rowIndex;
        vector<int> res(rowIndex), temp(rowIndex);
        for (int i = 0; i < rowIndex; i++)
        {
            copy(res.begin(), res.end(), temp.begin());
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    res[j] = 1;
                }
                else
                {
                    res[j] = temp[j] + temp[j - 1];
                }
            }
        }
        return res;
    }
};