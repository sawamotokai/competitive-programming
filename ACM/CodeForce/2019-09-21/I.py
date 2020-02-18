import re

T = input()


def findPrefix(string):
    nums = set([str(n) for n in range(0, 10)])
    if string[0] not in nums:
        return - 1
    if string == "":
        return -1
    for i in range(len(string)):
        if string[i] not in nums:
            return string[:i]


print(findPrefix(T))
