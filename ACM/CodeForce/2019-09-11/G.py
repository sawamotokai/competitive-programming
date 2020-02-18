

n, s = input().split()
n = int(n)
s = int(s)
A = [int(num) for num in input().split()]

dominations = [1]
for i in range(n):
    if dominations[i] * A[i] > s:
        break
    dominations.append(dominations[i] * A[i])


count = 0
dominations.sort(reverse=True)

for j in range(len(dominations)):
    while s >= dominations[j]:
        s -= dominations[j]
        count += 1
    if s == 0:
        break

print(count)
