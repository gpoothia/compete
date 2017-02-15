# http://codeforces.com/contest/754/problem/A

n= int(raw_input())
arr = map(int, raw_input().split(' '))
#print n
#print arr
if sum(arr) != 0:
  print "YES"
  print "1"
  print "1 " + str(len(arr))
else:
  found = -1
  for i in xrange(len(arr) - 1):
    leftarr = arr[0:i+1]
    rightarr = arr[i+1:]
    #print leftarr, rightarr
    if sum(leftarr) != 0 and sum(rightarr) != 0:
      #print found
      found = i
      break

  if found == -1:
    print "NO"
  else:
    print "YES"
    print "2"
    print "1 " + str(i+1)
    print  str(i+2) + " " + str(len(arr))
    #for i in xrange (i):
    #  print arr[i]
    #for i in xrange(i+1, len(arr) -1, 1):
    #  print arr[i]


