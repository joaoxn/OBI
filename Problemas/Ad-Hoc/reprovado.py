
n = int(input()) # 1<=N<=100

alunos = []
for i in range(n):
    alunos.append(input().split())
    alunos[i][1] = int(alunos[i][1])

alunos.sort(key=lambda x: x[1])
print(alunos[0][0])