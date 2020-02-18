
fibonacci = [1, 1]


while len(str(fibonacci[-1])) < 1000:

    nex = fibonacci[-1] + fibonacci[-2]
    fibonacci.append(nex)
    print(nex)
    print("")

print(len(fibonacci))
print(fibonacci[-1])

