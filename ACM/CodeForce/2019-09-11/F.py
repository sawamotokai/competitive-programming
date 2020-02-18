a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)

stay = True

origNum = c if c % 2 == 1 else c // 2

if origNum - a < b - origNum:
    stay = False
elif origNum == c and origNum - a == b - origNum:
    stay = False

print("Stay with this envelope" if stay else "Take another envelope")
