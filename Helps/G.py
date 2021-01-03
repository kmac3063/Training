def f(symb):
    if symb >= '0' and symb <= '9':
        return int(symb)
    return int((ord(symb) - ord('A') + 10))

def toDec(s, a):
    ans = 0
    i = len(s) - 1
    a = int(a)
    s = str(s)
    for symb in s:
        ans += f(symb) * (a ** i)
        i -= 1
    return ans

def toSymb(a):
    if (a < 10):
        return str(a)
    return str(chr(ord('A') + a - 10))

def toB(dec, b):
    dec = int(dec)
    b = int(b)
    ans = ""
    while (dec != 0):
        ans += toSymb(dec % b)
        dec //= b
    return ans[::-1]

fin = open('input.txt', 'r')
fout = open('output.txt', 'w')
l = [line.strip() for line in fin]
a = int(l[0].split()[0])
b = int(l[0].split()[1])
s = l[1]

dec = toDec(s, a)
toB = toB(dec, b)
if not toB:
    fout.write("0")
else:
    fout.write(str(toB))