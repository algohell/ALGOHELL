# 백준 2941

test = input()

words = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for w in words:
  ans = test.replace(w, '!')

  
print(len(ans))