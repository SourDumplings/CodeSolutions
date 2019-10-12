str1 = input()
# print(str1)
str2 = input()
# print(str2)

l1 = len(str1)
l2 = len(str2)

i = str1.find(str2)
while (i != -1):
    str1 = str1.replace(str2, '')
    i = str1.find(str2)

print(str1)
