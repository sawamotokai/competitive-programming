
def factorial(n):
    ret=1
    for i in range(1, 1+n):
        ret *= i
    return ret
    
print(factorial(9))
print(factorial(5))

print(factorial(9)*7)

boundry=2450160

def facSumOfDig(n):
    n = str(n)
    ret=0
    for i in range(len(n)):
        ret += factorial(int(n[i]))
    return ret
    
    
ans = 0
for num in range(10, boundry+1):
    if num == facSumOfDig(num):
        ans+=num
        
        
print(ans)