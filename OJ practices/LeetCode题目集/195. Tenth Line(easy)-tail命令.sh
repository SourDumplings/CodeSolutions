# Read from the file file.txt and output the tenth line to stdout.
# tail -n +10 表示从第十行开始显示到结尾，head -1表示查看第一行
tail -n +10 "file.txt" | head -1