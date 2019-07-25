{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "#5. Longest Palindromic Substring\n",
    "s = \"babad\"\n",
    "# 이게 유명한가 봅니다..;;\n",
    "# 공식도 있고 그 공식을 코드로 옮겨 놓은게 많았습니다\n",
    "# 보고 참고해서 작성 했습니다.\n",
    "if len(s) <= 1:\n",
    "    return s\n",
    "\n",
    "char = \"\"\n",
    "\n",
    "for i in range(len(s)): # 앞서부터\n",
    "    for j in range(len(s), 0, -1): # 뒤에서부터\n",
    "        if s[i:j] == s[i:j][::-1]:\n",
    "            char = s[i:j]\n",
    "            return char"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.6.5"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
