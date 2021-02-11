n = int(input())
if n == 1:
    print(7)
elif (n == 2):
    print(18)
else:
    n -= 1
    print((18 + (12 + (12 + (n - 2) * 2)) * (n - 1) // 2) % 998244353)
