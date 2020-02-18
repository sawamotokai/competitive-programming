

def singleNumNumOfLet(n):
    if n == "1" or n == "2" or n == "6":
        return 3
    if n == "4" or n == "5" or n == "9":
        return 4
    if n == "0":
        return 0
    return 5

def secondDigitNum(twoDigit):
    ret = singleNumNumOfLet(twoDigit[1])
    n = twoDigit[0]
    if n == "7":
        return ret + 7
    if n == "8" or n == "3" or n == "2" or n=="9":
        return ret + 6
    if n == "1":
        return teens(twoDigit[1])
    if n == "0":
        return ret
    return ret + 5

def teens(n):
    if n == "0":
        return 3
    if n == "1" or n == "2":
        return 6
    if n == "3" or n == "4" or n == "9":
        return 8
    if n == "6" or n == "5":
        return 7
    return 9


def numToLetter(n):
    s = str(n)
    ret = 0
    if len(s) == 3:
        if s[1] != "0" or s[2] != "0":
            ret += 3
        ret += len("hundred")
        ret += singleNumNumOfLet(s[0])
        ret += secondDigitNum(s[1:])
    if len(s) == 2:
        ret += secondDigitNum(s)
    if len(s) == 1:
        ret += singleNumNumOfLet(s)

    return ret

count = 0
for i in range(1, 1000):
    count += numToLetter(i)

print(secondDigitNum("38"))
print(numToLetter(100))
print(count+len("onethousand"))