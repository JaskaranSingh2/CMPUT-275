from functools import reduce as foldr


def adderGenerator(x):
  # This function returns a unary function
  # that adds x to its parameter
  return lambda y: x + y





add5 = adderGenerator(5)
add10 = adderGenerator(10)

list1 = [1, 2, 3, 4, 5]
list2 = [1, 2, 3]

print(list(map(add5, list1)))
print(list(map(add10, list2)))

print(list(map(adderGenerator(-10), list1)))


print(foldr(lambda x, y: x + y, list1, 0))
print(foldr(lambda x, y: x * y, list1, 1))


print(foldr(lambda x, y: x*y, filter(lambda x: x%2==0, list1), 1))
