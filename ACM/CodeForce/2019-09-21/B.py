

S_input = input()

S_input = S_input.split()


def palindrome(S):
    for i in range(len(S)):
        for j in range(len(S)):
            if S[i] == S[j]:
                isInsidePalindrom = True
                for k in range(1, abs(j - i) // 2 + 1):
                    if S[i + k] != S[j - k]:
                        isInsidePalindrom = False
                        break
                if not isInsidePalindrom:
                    break
                restOfStr = len(S) - j + 1
                for l in range(1, restOfStr + 1):
                    if S[i - l] != S[j + l]:
                        for m in range(len(S) - 2, -1, -1):
                            S.append(S[m])
                            return S  # not palandrome at all
                for n in range(i - restOfStr, -1, -1):
                    S.append(S[n])
                return S


print(palindrome(S_input))
