# Go North: (x,y) -> (x,y-1)
# Go East: (x,y) -> (x+1,y)
# Go South: (x,y) -> (x,y+1)
# Go West: (x,y) -> (x-1,y)

#0 wall
#1 path

import sys
sys.setrecursionlimit(1500)
class Rat:
    def __init__(self, maze_in):
        self.x_moves = [0, 1, 0, -1]
        self.y_moves = [-1, 0, 1, 0]
        self.board = [[0 for i in range(4)] for j in range(4)]
        self.maze = maze_in

    def print_maze(self):
        for i in range(4):
            for j in range(4):
                print(self.board[i][j], end=' ')
            print('')

    def find_path(self, x_start, y_start, x_des, y_des):
        self.board[x_start][y_start] = 1
        if (x_start == x_des) and (y_start == y_des):
            self.print_maze()
            exit()
        for i in range(4):
            u = x_start + self.x_moves[i]
            v = y_start + self.y_moves[i]
            if(u >= 0) and (u < 4) and (v >= 0) and (v < 4) and (self.maze[u][v] == 1) and (self.board[u][v] == 0):
                self.find_path(u, v, x_des, y_des)
        self.board[x_start][y_start] = 0


maze = [[1, 0, 0, 0],
        [1, 1, 0, 1],
        [0, 1, 0, 0],
        [1, 1, 1, 1]]
test = Rat(maze)
test.find_path(0,0,3,3)
test.print_maze()
