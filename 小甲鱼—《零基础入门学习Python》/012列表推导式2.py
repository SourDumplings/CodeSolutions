#列表推导式2
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
list1 = ['1.Just do it', '2.一切皆有可能', '3.让编程改变世界', '4.Impossible is nothing']
list2 = ['4.阿迪达斯', '2.李宁', '3.鱼C工作室', '1.耐克']

list3 = [name + '：' + slogan[2:] for slogan in list1 for name in list2 if slogan[0] == name[0]]

for each in list3:
    print(each)
