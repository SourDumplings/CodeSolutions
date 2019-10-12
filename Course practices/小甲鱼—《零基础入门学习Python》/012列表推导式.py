#列表推导式
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
list1=[]
for x in range(10):
    for y in range(10):
        if (x%2 == 0) and (y%2 != 0):
            list1.append((x, y))
print(list1)
