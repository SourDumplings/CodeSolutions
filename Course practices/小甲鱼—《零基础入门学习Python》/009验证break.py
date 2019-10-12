#验证break
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
bingo = '酸饺子是帅哥'
answer = input('请输入酸饺子最想听到的一句话：')

while True:
    if answer == bingo:
        break
    else:
        answer = input('错啦！输对了才能退出游戏：')
        
print('厉害了我的哥~')
print('不玩啦^_^')
