def sortAutores(a):
    aSep = a.split(' ')
    return aSep[1]+" "+aSep[0]

t = 0
while True:
    t += 1
    n = int(input())
    if n == 0: break
    grafo: dict[str,list] = dict()
    dist: dict[str,int] = {"P. Erdos": 0}

    autores = []

    for _ in range(n):
        article = input()
        article = article[:-1]
        people = article.split(", ")
        
        for person in people:
            if person not in autores and person != "P. Erdos":
                autores.append(person)

            others = people.copy()
            others.remove(person)
            if person in grafo:
                grafo[person] += others
            else:
                grafo[person] = others
    
    autores.sort(key=sortAutores)

    queue = ["P. Erdos"]
    idx = 0
    while idx < len(queue):
        v = queue[idx]
        if v in grafo:
            for u in grafo[v]:
                if u in dist:
                    dist[u] = min(dist[u],dist[v]+1)
                else:
                    dist[u] = dist[v]+1
                    queue.append(u)
        idx += 1
    
    print(f"Teste {t}")
    for autor in autores:
        print(f"{autor}: {dist[autor] if autor in dist else 'infinito'}")
    print()


