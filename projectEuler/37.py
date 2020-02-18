
def truncatable(d):
    size = len(str(d))
    digits = [str(d)[i] for i in range(size)]
    if (digits[0] != "3" and digits[0] != "7") or (digits[size - 1] != "3" and digits[size - 1] != "7"):
        return False
    if "2" in digits or "4" in digits or "5" in digits or "6" in digits or "8" in digits:
        return False
    if not prime(d):
        return False
    for i in range(size-1):
        left = int("".join(digits[0: size - i]))
        right = int("".join(digits[i:]))
        if not prime(left) or not prime(right):
            return False
    return True


def prime(n):
    for i in range(2, n // 2 + 2):
        if n % i == 0:
            return False
    return True


sum = 0
count = 0
i = 0
while True:
    if truncatable(i):
        count += 1
        print(count)
        sum += i
    i += 1
    if count == 11:
        print(sum)
        break

# print(truncatable(25234))
