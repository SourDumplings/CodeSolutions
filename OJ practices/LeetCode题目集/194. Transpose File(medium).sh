###
 # @Author: SourDumplings
 # @Date: 2020-12-20 09:07:50
 # @Link: https://github.com/SourDumplings/
 # @Email: changzheng300@foxmail.com
 # @Description: https://leetcode-cn.com/problems/transpose-file/

# awk是一行一行地处理文本文件，运行流程是：

# 1.先运行BEGIN后的{Action}，相当于表头
# 2.再运行{Action}中的文件处理主体命令
# 3.最后运行END后的{Action}中的命令
# 4.有几个经常用到的awk常量：NF是当前行的field字段数；NR是正在处理的当前行数。

# 注意到是转置，假如原始文本有m行n列（字段），那么转置后的文本应该有n行m列，即原始文本的第一行的每个字段都对应新文本的一行。我们可以用数组res来储存新文本，将新文本的每一行存为数组res的一个元素。

# 在END之前我们遍历file.txt的每一行，并做一个判断：在第一行时，每碰到一个字段就将其按顺序放在res数组中；从第二行开始起，每碰到一个字段就将其追加到对应元素的末尾（中间添加一个空格）。

# 文本处理完了，最后需要输出。在END后遍历数组，输出每一行。注意printf不会自动换行，而print会自动换行。

# 作者：gao-si-huang-bu
# 链接：https://leetcode-cn.com/problems/transpose-file/solution/awkming-ling-yong-shu-zu-chu-cun-dai-shu-chu-jie-g/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
###

awk '{
    for (i=1;i<=NF;i++){
        if (NR==1){
            res[i]=$i
        }
        else{
            res[i]=res[i]" "$i
        }
    }
}END{
    for(j=1;j<=NF;j++){
        print res[j]
    }
}' file.txt


