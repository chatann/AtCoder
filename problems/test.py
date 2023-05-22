from scipy.special import comb

h, w, k = map(int, input().split())

com = comb(h*w, k, exact=True)

for x in range()