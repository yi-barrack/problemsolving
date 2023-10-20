n, m = int(input())

A = []
B = []

for i in range(0,n):
    for j in range(0,m):
        A[i][j] = int(input())

for i in range(0,n):
    for j in range(0,m):
        B[i][j] = int(input())

for i in range(0,n):
    for j in range(0,m):
        A[i][j] += B[i][j]

for i in range(0,n):
    for j in range(0,m):
        print(A[i][j], end=' ')
    print()