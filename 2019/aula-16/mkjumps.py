grid = None

def leftmost(array):
    for i in range(len(array)):
        if array[i]:
            return i
def debug():
    global grid
    for i in range(10):
        for j in range(10):
            if grid[i][j]:
                print(".", end="")
            else:
                print("#", end="")
        print()
    print()

def all_moves():
    return [
        (-2, -1), (-1, -2),
        (-2, 1), (-1, 2),
        (2, -1), (1, -2),
        (2, 1), (1, 2)
    ]

def valid(i, j):
    global grid
    if i<0 or i>=10:
        return False
    if j<0 or j>=10:
        return False
    return grid[i][j]

def dfs(i, j, total):
    global grid
    best = total-1
    grid[i][j] = False
    for di, dj in all_moves():
        if valid(i+di, j+dj):
            best = min(best, dfs(i+di, j+dj, total-1))
        if best==0:
            return 0
    grid[i][j] = True
    return best

def main():
    global grid
    test = 0
    while True:
        line = [int(x) for x in input().split()]
        n = line.pop(0)
        if n == 0:
            break
        grid = [[False]*10 for i in range(10)]
        total = 0
        for i in range(n):
            start = line.pop(0)
            length = line.pop(0)
            total += length
            for j in range(length):
                grid[i][start+j] = True
        left = leftmost(grid[0])
        solution = dfs(0, left, total)
        test += 1
        print("Case %d, %d %s can not be reached." % (test, solution, (solution == 1) and "square" or "squares"))

main()

