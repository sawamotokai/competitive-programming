def factorial(n):
    ret = 1
    while n > 0:
        ret *= n
        n -= 1
    return ret

def sumDigits(n):
    s = str(n)
    ret = 0
    for letter in s:
        ret += int(letter)


    print(ret)


sumDigits(factorial(100))