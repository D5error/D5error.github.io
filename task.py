c = [0] * 1000
def C(n):
    if c[n] != 0:
        return C[n]
    if n == 0:
        c[n] = 1
    else:
        c[n] = 2 * (2 * n - 1) / (n + 1) * C(n - 1)
    return c[n]
    
print(C(20) % 97)