/*
 * @Autor: SourDumplings
 * @Date: 2019-10-30 11:17:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/flood-fill/
 */

class Solution
{
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
        {
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }

    public void dfs(int[][] image, int sr, int sc, int oldColor, int newColor)
    {
        if (image[sr][sc] == oldColor)
        {
            image[sr][sc] = newColor;
            if (sr >= 1)
            {
                dfs(image, sr - 1, sc, oldColor, newColor);
            }
            if (sr < image.length - 1)
            {
                dfs(image, sr + 1, sc, oldColor, newColor);
            }
            if (sc >= 1)
            {
                dfs(image, sr, sc - 1, oldColor, newColor);
            }
            if (sc < image[0].length - 1)
            {
                dfs(image, sr, sc + 1, oldColor, newColor);
            }
        }
    }
}