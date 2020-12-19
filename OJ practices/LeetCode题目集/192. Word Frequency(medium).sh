###
 # @Author: SourDumplings
 # @Date: 2020-12-19 20:02:34
 # @Link: https://github.com/SourDumplings/
 # @Email: changzheng300@foxmail.com
 # @Description: https://leetcode-cn.com/problems/word-frequency/

# 1、首先cat命令查看words.txt
# 2、tr -s ' ' '\n'将空格都替换为换行 实现分词
# 3、sort排序 将分好的词按照顺序排序
# 4、uniq -c 统计重复次数（此步骤与上一步息息相关，-c原理是字符串相同则加一，如果不进行先排序的话将无法统计数目）
# 5、sort -r 将数目倒序排列
# 6、awk '{print $2,$1}' 将词频和词语调换位置打印出来

# 作者：money666
# 链接：https://leetcode-cn.com/problems/word-frequency/solution/yi-bu-yi-bu-ji-suan-ci-pin-by-money666/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
### 

cat words.txt |tr -s ' ' '\n' |sort|uniq -c|sort -r|awk '{print $2,$1}'