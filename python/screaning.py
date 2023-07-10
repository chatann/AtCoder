n = int(input())

queries = []
query = []
for i in range(n):
    line = input()
    if line[0] == "1":
        a, b = map(int, line[2:].split())
        query.append([a, b])
    else:
        queries.append(query)
        query = []

cand = []
max_a, max_b = 10**9, 10**9
for query in queries:
    cand += query
    cand.sort(key=lambda x: (x[0], x[1]))
    indices_to_remove = []
    for i in range(len(cand)):
        if a > max_a and b > max_b:
            
        max_a = cand[i][0]
    print(ans)
    cand = ans