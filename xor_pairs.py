# http://codeforces.com/contest/742/problem/B

n,x = map(int, raw_input().split(' '))
list = map(int, raw_input().split(' '))

#Create frequency table
ft = dict()
for i in list:
  curr = ft.get(i, 0)
  ft[i] = curr+1
#print ft

pair_cnt = 0
if x != 0:
  # For each member i add to count FT [ i XOR  x]
  for i in list:
    pair_cnt += ft.get(i^x, 0)
  pair_cnt = pair_cnt/2
else:
  for i in ft:
    fi = ft[i]
    if fi > 0:
      # n choose 2
      pair_cnt += fi * (fi -1) /2
print pair_cnt


