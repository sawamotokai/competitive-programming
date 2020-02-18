import itertools


def prime(n):
    for i in range(2, n//2+2):
        if n % i == 0:
            return False
    return True


def circPrime(d):

    digits = [str(d)[i] for i in range(len(str(d)))]
    if "2" in digits or "4" in digits or "5" in digits or "6" in digits or "8" in digits:
        return False
    if not prime(d):
        return False
    size = len(digits)
    for _ in range(size-1):
        popped = digits.pop(0)
        digits.append(popped)
        if not prime(int("".join(digits))):
            return False
    return True


count = 13
for i in range(100, 1000000):
    print(i)
    if circPrime(i):
        count += 1
print(count)
