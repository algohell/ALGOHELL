C = int(input())
caselist = [list(map(int,input().split())) for _ in range(C)]

for case in caselist:
  avg = sum(case[1:])/case[0]
  count = len(list(filter(lambda x: x>avg,case[1:])))
  ratio = (count/case[0])*100
  print("{:.3f}%".format(ratio))