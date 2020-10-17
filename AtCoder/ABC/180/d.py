X, Y, A, B = map(int, input().split())

ans = 0
while X < Y:
    if X * A < X + B:
        X *= A
    else:
        X += B
    ans += 1


print(ans)
