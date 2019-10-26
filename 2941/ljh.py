S = input()
S = [S[i] for i in range(len(S))]
count = 0
for i in range(len(S)-1,-1,-1):
  if S[i]=="=":
    if i>=2 and S[i-1]=="z" and S[i-2]=="d":
      count+=1
      S[i-2:i+1] = "000"
    else:
      count+=1
      S[i-1:i+1] = "00"
  elif S[i]=="-":
    count+=1
    S[i-1:i+1] = "00"
  elif S[i]=="j":
    if i>=1 and (S[i-1]=="n" or S[i-1]=="l"):
      count+=1
      S[i-1:i+1] = "00"
    else:
      count+=1
      S[i] = "0"
  elif S[i]!="0":
    count+=1
    S[i] = "0"

print(count)
