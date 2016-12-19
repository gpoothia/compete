def foo(x,y):
  return (x+y)

a = [1,2,3]
b = [4,5,6]
m = map(foo, a ,b)
l = list(m)
print(l)

ha = {1:2, 10:11}
ha[20] = 21
for i in ha:
  print("key"  + str(i) + "val" + str(ha[i]))
