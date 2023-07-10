s_before = 0
ans = "Yes"
s = list(map(int, input().split()))
for i in range(8):
    if s[i] < s_before:
        ans = "No"
        break
    if s[i] < 100 or s[i] > 675:
        ans = "No"
        break
    if s[i] % 25 != 0:
        ans = "No"
        break
    s_before = s[i]

print(ans)