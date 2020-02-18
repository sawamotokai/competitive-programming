def isPalindome(n):
    n=str(n)
    for i in range(1, len(n)//2+2):
        if n[i-1] != n[-i]:
            return False
    return True
    
    
def toBinary(n):
    ret=[]
    while n != 1 and n!=0:
        ret.insert(0,str(n%2))
        n = n//2
    ret.insert(0, str(1))
    print("".join(ret))
    target = int("".join(ret))
    return target
    
    
print(toBinary(7))


ans =0
for i in range(1000000):
    print(i)
    if isPalindome(i):
        if isPalindome(toBinary(i)):
            ans += i
            
print(ans)
