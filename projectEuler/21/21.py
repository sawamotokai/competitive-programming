import math

def d(n):
    ret = 0
    for i in range(1, n):
        if n != i:
            if n % i == 0:
                ret += i
    return ret


def run():
    result = 0
    for i in range(1, 10000):
        n = d(i)
        m = d(n)
        if i != n:
            if i == m:
                result += i
            
    print(result)

# print(d(220))

run()
# i = 1
# n = d(i)
# m = d(n)
# if i == m:
#     print(i)