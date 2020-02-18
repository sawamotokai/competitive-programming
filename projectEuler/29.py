

print(5**0.5 % int(5**0.5))


def exponential(num):
    return num ** 0.5 % int(num ** 0.5) == 0


print(exponential(16))


s = set()
for a in range(2, 101):
    for b in range(2, 101):
        s.add(a ** b)

print(len(s))
