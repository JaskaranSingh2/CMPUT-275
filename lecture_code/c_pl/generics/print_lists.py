

l1 = [1, 2, 3, 4, 5]
l2 = ["hi", "bye", "wow"]

for i in l1:
  print(i)

for i in l2:
  print(i)


list(map(print, l1))

mapResult = map(print, l2)
for i in mapResult:
  1 + 1
  break


strres = list(map(lambda x: str(x) +"blah", l1))
print(strres)
