from copy import deepcopy

def post_increment(lst):
  myLst = deepcopy(lst)
  for i in range(len(lst)):
    lst[i] = lst[i] + 1
  return myLst



def pre_increment(lst):
  for i in range(len(lst)):
    lst[i] = lst[i] + 1
  return lst
