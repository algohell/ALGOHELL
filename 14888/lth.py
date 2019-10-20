def next_permutation(items):
  index = len(items) - 1
  while(index > 0 and items[index - 1] >= items[index]):
    index = index - 1
  
  if index == 0:
    return False
  
  jndex = len(items) - 1
  while(items[jndex] <= items[index - 1]):
    jndex = jndex - 1
  
  temp = items[index - 1]
  items[index - 1] = items[jndex]
  items[jndex] = temp

  i = index
  j = len(items) - 1

  while (i < j):
    temp = items[i]
    items[i] = items[j]
    items[j] = temp
    i = i + 1
    j = j - 1
  
  return True

n = int(input())
numbers = list(map(int, input().split()))
operators = list(map(int, input().split()))
mapped = list()
for i in range(len(operators)):
  for j in range(operators[i]):
    mapped.append(i)

hasNext = True
max = -987654321
min = 987654321
while(hasNext):
  ans = numbers[0]
  for i in range(1, len(numbers)):
    if mapped[i - 1] == 0:
      ans = ans + numbers[i]
    elif mapped[i - 1] == 1:
      ans = ans - numbers[i]
    elif mapped[i - 1] == 2:
      ans = int(ans * numbers[i])
    else:
      ans = int(ans / numbers[i])
  if ans > max:
    max = ans
  if ans < min:
    min = ans
    
  hasNext = next_permutation(mapped)
print(max)
print(min)