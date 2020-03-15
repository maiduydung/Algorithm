# 00000
# 00001
# 00010
n = int(input())
arr = [0]*n

def binary(i: int):
    for v in [0,1]:
        arr[i] = v
        if (i >= n-1):
            print(*arr)
        else:
            binary(i+1)

if __name__ == "__main__":
    binary(0)