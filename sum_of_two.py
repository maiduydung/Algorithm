
# https://www.youtube.com/watch?v=sfuZzBLPcx4&t=603s

def sum_of_two(a , b, v):
    complements = set()
    for i in a:
        c = v - i
        print("c ", c)
        complements.add(c)

    for j in b:
        print("j ",j)
        if j in complements:
            return True
    return False

if __name__ == "__main__":

    a = [1, 3, 5]
    b = [2, 4, 6]
    print(sum_of_two(a, b, 9))