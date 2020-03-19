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

def BCKNIGHT(SIZE: int, X_in: int, Y_in: int):
    count = 0
    result = [[0]]
    checked = set()

    board = [[0 for x_size in range(SIZE)] for y_size in range(SIZE)]
    print(board)

    if count == SIZE^2:
        return result
    else:
        for x in range(X_in,SIZE):
            for y in range(Y_in ,SIZE):
                if(abs(x - y) <= 3):
                    print(board[x][y], x, y)
                # if(abs(X))

BCKNIGHT(4,1,2)