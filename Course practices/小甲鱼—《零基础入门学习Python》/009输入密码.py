#输入密码
#Coding 酸饺子

print('-------------酸饺子学Python-------------')

count = 3
code = 'SourDumplings'

while count != 0:
    guess = input('您好，请输入密码：')
    if guess == code:
        print('密码正确！')
        break
    elif '*' in guess:
        print('密码中不能含有*！')
        print('您还有', count, '次机会')
    else:
        count -= 1
        print('密码错误。您还有', count, '次机会！')
        
        
