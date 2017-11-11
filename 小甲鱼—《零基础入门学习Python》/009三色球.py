#三色球
#Coding 酸饺子

print('-------------酸饺子学Python-------------')

print('red\tyellow\tgreen\t')
for red in range(0, 4):
    for yellow in range(0, 4):
        for green in range(2, 7):
            if red + yellow + green == 8:
                print(red, '\t', yellow, '\t', green)
