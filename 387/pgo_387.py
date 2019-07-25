#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# 387 first-unique-character-in-a-string
s = "loveleetcode"
cs = Counter(s)
        #print(cs) 
        # Counter({'e': 4, 'l': 2, 'o': 2, 'v': 1, 't': 1, 'c': 1, 'd': 1})
for i, c in enumerate(s):
    if cs.get(c, 0) == 1:
        return i
    return -1

