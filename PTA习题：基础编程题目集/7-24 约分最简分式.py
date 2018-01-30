temp = input()

# print(temp)

numeritor = int(temp.split('/')[0])
denominator = int(temp.split('/')[1])

for i in range(numeritor, 2, -1):
    if not(numeritor % i) and not(denominator % i):
        numeritor /= i
        denominator /= i

print('%d/%d' % (numeritor, denominator))

