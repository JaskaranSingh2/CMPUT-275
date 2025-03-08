import random
size = int(input())
print(size)
for i in range(size):
  print(random.randint(-size*3, size*3))
