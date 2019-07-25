{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "\n",
    "#240 Search a 2D matrix\n",
    "# class Solution:\n",
    "#     def searchMatrix(self, matrix, target):\n",
    "matrix = [\n",
    "          [1,   4,  7, 11, 15],\n",
    "          [2,   5,  8, 12, 19],\n",
    "          [3,   6,  9, 16, 22],\n",
    "          [10, 13, 14, 17, 24],\n",
    "          [18, 21, 23, 26, 30]]\n",
    "if matrix:\n",
    "    r = 0\n",
    "    c = len(matrix)-1\n",
    "    \n",
    "    while r < len(matrix) and c >= 0:\n",
    "        val = matrix[r][c]\n",
    "        if val == target:\n",
    "            return True\n",
    "        \n",
    "        elif val > target:\n",
    "            c -= 1\n",
    "            \n",
    "        else:\n",
    "            r += 1\n",
    "            return False"
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
