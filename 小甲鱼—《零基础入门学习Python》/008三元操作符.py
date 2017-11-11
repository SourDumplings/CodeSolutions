#三元操作符
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
x, y, z = 6, 5, 4
small = x if (x < y and x < z) else (y if y < z else z)
