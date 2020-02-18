

N = int(input())
A = [int(color) for color in input().split()]
M = int(input())
K = []
X = []
for _ in range(M):
    k, x = input().split()
    k = int(k)
    x = int(x)
    K.append(k)
    X.append(x)


colorDict = {}
for color in A:
    if not color in colorDict:
        colorDict[color] = 1
    else:
        colorDict[color] += 1

times = 0
for i in range(M):
    if len(colorDict) == 1:
        break
    colorDict[A[K[i]-1]] -= 1
    if not X[i] in colorDict:
        colorDict[X[i]] = 1
    else:
        colorDict[X[i]] += 1
    A[K[i] - 1] = X[i]
    times += 1
    if colorDict[X[i]] == N:
        break


if len(set(A)) != 1:
    print(-1)
else:
    print(times)
