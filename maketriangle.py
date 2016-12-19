# http://codeforces.com/contest/667/problem/B
#n = int(input())
listnum  = list(map(int, input().split(" ")))
print (2*max(listnum) -  sum(listnum) + 1)
