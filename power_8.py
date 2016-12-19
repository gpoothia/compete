// http://codeforces.com/contest/742/problem/A

n = input()
l = (6, 8, 4, 2)
if n == 0:
  print 1
else:
  print l[n % 4]
