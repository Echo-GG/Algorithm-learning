def karatsuba(x, y):
    if x < 10 or y < 10:
        return x * y

    n = max(len(str(x)), len(str(y)))
    m = n // 2

    a, b = divmod(x, 10 ** m)
    c, d = divmod(y, 10 ** m)

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    ad_plus_bc = karatsuba(a + b, c + d) - ac - bd

    return ac * 10 ** (2 * m) + ad_plus_bc * 10 ** m + bd

# e.g.

print(karatsuba(1234, 5678))  # Output: 7006652