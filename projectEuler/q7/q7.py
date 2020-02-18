import math


def prime(idx):
    primes = []
    target = 2
    while len(primes) < 10001:
        isPrime = True
        for i in range(2, math.ceil(target / 2) + 1):
            if target % i == 0:
                isPrime = False
                break
        if isPrime:
            primes.append(target)
            # print(target)
        target += 1
    print(primes[0])
    print(primes[1])
    print(primes[2])

    return primes[idx]


print(prime(10000))
