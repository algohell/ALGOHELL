{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "# 387 first-unique-character-in-a-string\n",
    "s = \"loveleetcode\"\n",
    "cs = Counter(s)\n",
    "        #print(cs) \n",
    "        # Counter({'e': 4, 'l': 2, 'o': 2, 'v': 1, 't': 1, 'c': 1, 'd': 1})\n",
    "for i, c in enumerate(s):\n",
    "    if cs.get(c, 0) == 1:\n",
    "        return i\n",
    "    return -1"
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
