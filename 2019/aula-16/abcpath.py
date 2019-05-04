grid = None
longest = None

def dfs(y, x):
    global grid, longest
    if longest[y][x] > 0:
        return longest[y][x]
    best = 0
    for i in range(y-1, y+2):
        for j in range(x-1, x+2):
            if ord(grid[i][j]) == ord(grid[y][x])+1:
                best = max(best, dfs(i, j))
    longest[y][x]=best+1
    return longest[y][x]

def main():
    global grid, longest
    test = 0
    while True:
        height, width = [int(x) for x in input().split()]
        if width == 0 and height == 0:
            return
        grid = [['#']*(width+2)]*(height+2)
        longest = [[0]*(width+2)]*(height+2)
        for i in range(1, height+1):
            string = input()
            for j in range(1, width+1):
                grid[i][j] = string[j-1]
        best = 0
        for i in range(1, height+1):
            for j in range(1, width+1):
                if grid[i][j]=='A':
                    best = max(best, dfs(i, j))
        test+=1
        print("Case %d: %d" % (test, best))

main()
