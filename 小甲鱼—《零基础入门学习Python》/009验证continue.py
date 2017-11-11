#验证continue
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
for i in range(10):
    if i%2 != 0:
        print(i)
        continue
    i += 2
    print(i)
