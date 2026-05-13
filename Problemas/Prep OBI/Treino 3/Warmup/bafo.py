t = 1
while True:
    r = int(input())
    if r == 0:
        break
    aSum, bSum = 0, 0
    for i in range(r):
        a, b = map(int,input().split())
        aSum += a
        bSum += b
    
    print("Teste", t)
    print("Aldo" if aSum > bSum else "Beto")
    print()
    t += 1
