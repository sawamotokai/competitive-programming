def solve():
    s = input()
    if s[0] != "A":
        cnt = 0
        idx = -1
        for i in range(2, len(s) - 1):
            if s[i] == "C":
                cnt += 1
                idx = i
        if cnt == 1:
            sm = True
        for i in range(len(s)):
            if i == 0 or i == idx:
                continue
            if s[i] <= "z" and s[i] >= "a":
                pass
            else:
                sm = False

        if sm:
            print("AC")
            return
    print("WA")


solve()
