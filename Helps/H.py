fin = open('input.txt', 'r')
fout = open('output.txt', 'w')
l = [line.strip() for line in fin]
a = int(l[0].split()[0])
b = int(l[0].split()[1])

F = [0, 1]
for i in range(2, 201):
    F.append(F[i - 1] + F[i - 2])

def nod(a, b):
    if a == 0:
        return str(b)
    return nod(b % a, a)

fout.write(nod(F[b], F[a]))