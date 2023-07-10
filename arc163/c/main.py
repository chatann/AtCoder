t = int(input())
tree = [] * 9
tree[0] = 2
for i in range(1, 9):
    for j in range(len(tree[i-1])):
        x = tree[i-1][j]
        tree[i].append([x+1, x*(x+1)])
for i in range(t):
    n = int(input())
