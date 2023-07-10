h, w = map(int, input().split())
s = []
for i in range(h):
    word = input()
    s.append(list(word))

snuke = {"s": 0, "n": 1, "u": 2, "k": 3, "e": 4}
if s[0][0] != "s":
    print("No")
    exit()

ans = "No"
cand = [[0,0]]
while cand:
    new_cand = []
    for k in cand:
        i, j = k[0], k[1]
        neighbors = [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]
        next = (snuke[s[i][j]] + 1) % 5
        for l in neighbors:
            if 0 <= l[0] < h and 0 <= l[1] < w:
                tmp = snuke[s[l[0]][l[1]]]
                if tmp == next:
                    if l == [h-1, w-1]:
                        ans = "Yes"
                        break
                    new_cand.append(l)
        if ans == "Yes":
            break
    cand = new_cand

print(ans)