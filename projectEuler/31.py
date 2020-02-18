

denomination = [200, 100, 50, 20, 10, 5, 2, 1]

# waysToPay([20, 10, 5, 2, 1], 100)
# -> 100 // 20 = choises
#  for i in range(1, choises+1)
#


def waysToPay(denomination, amount):
    if len(denomination) == 1 or amount == 0:
        return 1
    result = 0
    coin = denomination[0]
    times = amount // coin

    for i in range(times + 1):
        amountLeft = amount - coin * i
        result += waysToPay(denomination[1:], amountLeft)
    return result


print(waysToPay(denomination, 200))
