/*
 * @Author: SourDumplings
 * @Date: 2020-09-24 14:56:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/word-ladder/
 */

class Solution
{
    public int ladderLength(String beginWord, String endWord, List<String> wordList)
    {
        int lth = beginWord.length();
        Map<String, List<Integer>> d = new HashMap<>();

        for (int j = 0; j < wordList.size(); j++)
        {
            String word = wordList.get(j);
            for (int i = 0; i < lth; i++)
            {
                String newWord = new StringBuilder(word.substring(0, i)).append(".")
                    .append(word.substring(i + 1, lth)).toString();
                if (!d.containsKey(newWord))
                {
                    d.put(newWord, new ArrayList<>());
                }
                d.get(newWord).add(j);
            }
        }
        int level = 1;
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] checked = new boolean[wordList.size()];
        Arrays.fill(checked, false);
        Set<Integer> nextLevel = new HashSet<>();

        for (int i = 0; i < lth; i++)
        {
            String newWord = new StringBuilder(beginWord.substring(0, i)).append(".")
                .append(beginWord.substring(i + 1, lth)).toString();
            if (d.containsKey(newWord))
            {
                nextLevel.addAll(d.get(newWord));
            }
        }
        q.addAll(nextLevel);
        while (!q.isEmpty())
        {
            nextLevel.clear();
            ++level;
            while (!q.isEmpty())
            {
                int thisIndex = q.poll();
                checked[thisIndex] = true;
                String thisWord = wordList.get(thisIndex);
                if (thisWord.equals(endWord))
                {
                    return level;
                }
                for (int i = 0; i < lth; i++)
                {
                    String newWord = new StringBuilder(thisWord.substring(0, i)).append(".")
                        .append(thisWord.substring(i + 1, lth)).toString();
                    if (d.containsKey(newWord))
                    {
                        List<Integer> nextIndexes = d.get(newWord);
                        for (int nextIndex : nextIndexes)
                        {
                            if (!checked[nextIndex])
                            {
                                nextLevel.add(nextIndex);
                            }
                        }
                    }
                }
            }
            q.addAll(nextLevel);
        }

        return 0;
    }
}

