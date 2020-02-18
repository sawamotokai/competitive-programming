import math


def isPalindromic(num):
    string = str(num)

    for i in range(1, len(string)):
        if string[i - 1] != string[-i]:
            return False
    return True


largest = 0

for i in range(1000, 99, -1):
    for j in range(1000, 99, -1):
        if isPalindromic(i * j):
            if largest < i * j:
                largest = i * j

print(largest)
