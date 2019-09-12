class Solution:
    def exist(self, board, word):
        # board의 boundary를 '0'으로 감싸서 index out of bounds를 막는다.
        board = [['0' for _ in range(len(board[0]))]] + board + [['0' for _ in range(len(board[0]))]]
        for i in range(len(board)):
            board[i] = ['0'] + board[i] +['0']
            # print(board[i])
        def dfs(c,i,j,board,word): # c : word의 index  # i,j : board의 index
            if c>=len(word): # word하고 일치하는 부분을 찾음
                return True
            if board[i][j]=='0': # 경계선
                return False
            if word[c]!=board[i][j]: # word와 board의 문자열이 일치하지 않는 경우 False
                return False
            board[i][j]='?' # 이미 방문한 부분을 알파벳이 아닌 문자열로 채움
            # print("-----------------------")
            # for b in board:
            #     print(b)
            # print("-----------------------")
            if (dfs(c+1,i+1,j,board,word) or 
                dfs(c+1,i,j+1,board,word) or 
                dfs(c+1,i-1,j,board,word) or 
                dfs(c+1,i,j-1,board,word)): # 해당 문자열의 사방을 탐색하며 DFS 실시. 하나라도 True가 나오면 True를 반환
                return True
            board[i][j] = word[c] # 올바른 경로 탐색이 아닐 경우 ?를 문자열로 다시 교체
            return False
        for i in range(1,len(board)):
            for j in range(1,len(board[0])):
                if board[i][j]==word[0]: # 첫 문자
                    if dfs(0,i,j,board,word):
                        return True
        return False


s = Solution()
board = [["C","A","A"],["A","A","A"],["B","C","D"]]
word = "AAB"
print(s.exist(board,word))