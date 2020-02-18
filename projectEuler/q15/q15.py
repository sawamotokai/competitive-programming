
def factorial(n):
    if n == 1:
        return 1

    return n * factorial(n - 1)
    
def routes(n):
    return factorial(2*n) / (factorial(n) ** 2)
    
print(routes(20))