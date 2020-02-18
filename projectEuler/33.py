from fractions import Fraction


def oddFraction(a, b):
    expected = a / b
    actual = 0
    a_1 = int(str(a)[1])
    a_10 = int(str(a)[0])
    b_1 = int(str(b)[1])
    b_10 = int(str(b)[0])
    try:
        error = (a_10 * a_1) / (b_10 * b_1)
    except:
        return False
    if expected == error:
        if a_1 == b_1 or a_1 == b_10 or a_10 == b_1 or a_10 == b_10:
            if b_10 != 0 and b_1 != 0:
                print(f"{a}/{b}")
                return True


def largestCommonFactor(a, b):
    for i in range(10, 0, -1):
        if a % i == 0 and b % i == 0:
            return i


numerator = 1
denominator = 1
for a in range(10, 100):
    for b in range(a+1, 100):
        if oddFraction(a, b):
            numerator *= a
            denominator *= b
y = numerator / denominator
print(y)
x = Fraction(y)
print(x)
print(str(x).split('/')[1])
n = 1 * 1 * 1 * 1
d = 4 * 5 * 5 * 1

LCF = largestCommonFactor(n, d)
print(LCF)
n = n // LCF
d = d // LCF

print(d)
