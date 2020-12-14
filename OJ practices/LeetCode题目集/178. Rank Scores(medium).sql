/*
 * @Author: SourDumplings
 * @Date: 2020-12-14 11:45:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/rank-scores/

 最后的结果包含两个部分，第一部分是降序排列的分数，第二部分是每个分数对应的排名。
 对于第二部分，我们可以先提取出大于等于 X 的所有分数集合 H，将 H 去重后的元素个数就是 X 的排名。
 从结果的角度来看，第二部分的 Rank 是对应第一部分的分数来的，所以这里的 X 就是上面的 s1.Score

 参考：https://leetcode-cn.com/problems/rank-scores/solution/fen-cheng-liang-ge-bu-fen-xie-hui-rong-yi-hen-duo-/
 */

SELECT
    s1.Score as Score,
    (
        SELECT
            COUNT(DISTINCT s2.Score)
        FROM
            Scores s2
        WHERE
            s2.Score >= s1.Score
    ) as `Rank`
FROM
    Scores s1
ORDER BY
    s1.Score DESC
