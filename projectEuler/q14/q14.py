import math

m = 0
longest = 0

for num in range(1, 1000000):
    
    # print(num)
    seqLen = 0
    n = num
    # print(n)
    while n != 1:
        if n % 2 == 0:
            n = n/2
        else:
            n = 3 * n + 1
        seqLen += 1
    
    if seqLen > longest:

        m = num
        longest = seqLen 

print(m)