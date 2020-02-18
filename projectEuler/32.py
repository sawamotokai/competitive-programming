from functools import reduce
upperBound = 99999


def pandigital(num):
    a = 0
    b = 0
    for i in range(1, 10000):
        if num % i == 0:
            a = i
            b = int(num / i)
            if numOfDegit(a) + numOfDegit(b) + numOfDegit(num) == 9:
                if "123456789" == concatNums(a, b, num):
                    print(f"{a} x {b} = {num}")
                    return num


def numOfDegit(num):
    return len(str(num))


def concatNums(a, b, prod):
    s = ""
    s += str(a)
    s += str(b)
    s += str(prod)
    return "".join(sorted(s))


s = set()
for i in range(1, upperBound):

    if pandigital(i) is not None:
        s.add(i)

sum = 0
for e in s:
    sum += e
print(sum)
