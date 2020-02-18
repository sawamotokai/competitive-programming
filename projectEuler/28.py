from functools import reduce
n = [i for i in range(1, 1003, 2)]


def formula(num):
    if num == 1:
        return 1
    return 4 * num ** 2 - 6 * num + 6


print(reduce(lambda x, y: x+y, map(formula, n)))
