
def sumOfDigits(n):
    s = str(n)
    ret = 0
    for letter in s:
        ret += int(letter)
    
    return ret


print(sumOfDigits(2**1000))