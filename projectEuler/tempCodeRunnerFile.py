0
count = 0
i = 0
while True:
    if truncatable(i):
        count += 1
        print(count)
        sum += i
    i += 1
    if count == 13:
        print(sum)
        break
