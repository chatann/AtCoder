# abc086 c - Traveling

n = int(input())
t = []
x = []
y = []

for i in range(n):
    t_, x_, y_ = map(int, input().split())
    t.append(t_)
    x.append(x_)
    y.append(y_)

for i in range(n):
    if i == 0:
        if x[i] + y[i] > t[i] or (x[i] + y[i] - t[i]) % 2 == 1:
            print("No")
            exit()
    else:
        if x[i] + y[i] > t[i] or (x[i] + y[i] - t[i]) % 2 == 1 or abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) > t[i] - t[i-1]:
            print("No")
            exit()
        
print("Yes")