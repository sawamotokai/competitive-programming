num = 1
while True:
    ret = True
    for i in range(1, 21):
        if num % i != 0:
            ret = False
            break
    if ret:
        print(num)
        break
    else:
        num += 1
        continue
