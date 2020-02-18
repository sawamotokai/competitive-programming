

def getPattern(denomi):
    remainders = []
    cur = 1
    while True:
        cur *= 10
        if denomi <= cur:
            quotient = cur // denomi
            remainders.append(quotient)
            break

    idx = 0
    while True:
        
        try:
            nex = getNext(denomi, idx)
        except:
            # this is not infinite decimal.
            return []

        if nex not in remainders:
            remainders.append(nex)
            idx += 1
        else:
            isOk = True
            idxOfMatch = remainders.index(nex)
            for e in range(len(remainders[1 + idxOfMatch:])):
                if remainders[1 + idxOfMatch + e] != getNext(denomi, idx + 1 + e):
                    isOk = False
                    remainders.append(nex)
                    idx += 1
                    break
            if isOk:
                return remainders[idxOfMatch:]
        if len(remainders) > 1+len(str(denomi)):
            if remainders[-1] == remainders[-2] and remainders[-2] == remainders[-3] and remainders[-2] == remainders[-4]:
                return [remainders[-1]]

def getNext(denomi, curIdx):
    digitOfDenomi = len(str(denomi))
    cur=1

    for e in range(digitOfDenomi-1):
        cur *= 10
    quotient = 0
    for i in range(curIdx + 2):
        cur *= 10
        if cur < denomi:
            quotient = 0
        else:
            quotient = cur // denomi
            cur = cur % (quotient * denomi)
    return quotient


longest = []
longestD = 0

for d in range(1, 999):
    print(d)
    if len(getPattern(d)) > len(longest):
        longest = getPattern(d)
        longestD = d


print(len(longest))
print(longestD)