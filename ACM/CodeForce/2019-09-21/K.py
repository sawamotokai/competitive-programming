
numOfCases = int(input())
N = []
for _ in range(numOfCases):
    N.append(int(input()))


def NthFibonacchi(n):
    seq = [1, 1]
    if n == 1 or n == 2:
        return 1
    for i in range(2, n):
        seq.append(seq[-1] + seq[-2])
    return seq[-1]


def isGoodCouple(a, b):
    x = NthFibonacchi(a)
    y = NthFibonacchi(b)
    if (x + y) % 2 == 0:
        return False

    if x != 1 and y != 1:
        if x > y:
            if x % y == 0:
                return False
        else:
            if y % x == 0:
                return False

    return True


# N = [4]
for n in N:
    count = 1
    for i in range(1, 1 + n):
        if isGoodCouple(i, i+1):
            count += 1
    print(count)
