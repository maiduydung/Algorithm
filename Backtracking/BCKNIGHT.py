# https://www.spoj.com/PTIT/problems/BCKNIGHT/
# Input: Size N, cordinate X, Y
# 6 2 3

# Output:
# 36 17 6 29 8 11
# 19 30 1 10 5 28
# 16 35 18 7 12 9
# 23 20 31 2 27 4
# 34 15 22 25 32 13
# 21 24 33 14 3 26

# valid move |X-Y| <=3

class KnightsTour:
    def __init__(self, size_in, x_in, y_in):
        self.X = x_in
        self.Y = y_in
        self.Size = size_in
        self.squares = size_in * size_in 
        self.board = [[0 for i in range(self.Size)] for j in range(self.Size)]
        self.count = 0
        self.x_offset = [-2,-2,-1,-1, 1, 1, 2, 2]
        self.y_offset = [-1, 1,-2, 2,-2, 2,-1, 1]
        
    def print_board(self):
        #print(self.board)
        for i in range(self.Size):
            for j in range(self.Size):
                print(self.board[i][j], end=' ')
            print('')

    def move(self, x:int, y:int):
        self.count = self.count + 1
        self.board[x][y] = self.count
        for i in range(8):
            if(self.count == self.Size**2):
                self.print_board()
                exit()
            u = x + self.x_offset[i]
            v = y + self.y_offset[i]
            if(u >= 0) and (u < self.Size) and (v >= 0) and (v < self.Size) and (self.board[u][v] == 0):
                self.move(u, v)
            #board[u][v] = 0 => not travel there yet
        
        self.count = self.count - 1    
        self.board[x][y] = 0


    

test = KnightsTour(5, 0 ,0)
test.move(0, 0)
test.print_board()