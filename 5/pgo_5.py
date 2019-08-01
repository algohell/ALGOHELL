#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#5. Longest Palindromic Substring
s = "babad"
# 이게 유명한가 봅니다..;;
# 공식도 있고 그 공식을 코드로 옮겨 놓은게 많았습니다
# 보고 참고해서 작성 했습니다.
if len(s) <= 1:
    return s

char = ""

for i in range(len(s)): 
    for j in range(len(s), 0, -1):
        if len(char) >= j-i:
            pass
        elif s[i:j] == s[i:j][::-1]:
            char = s[i:j]
            return char

