from sys import stdin

t = int(input())
for i in range(t):
    line = stdin.readline().rstrip().split()
    if len(line) < 2:
        continue
    if line[0] == "Simon" and line[1] == "says":
        print(" ".join(line[2:]))
