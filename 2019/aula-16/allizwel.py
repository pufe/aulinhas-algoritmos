grid = None
string = 'ALLIZZWELL'

def dfs(y, x, p):
    global grid
    if p>=9:
        return True
    grid[y][x] = '.'
    for i in range(y-1, y+2):
        for j in range(x-1, x+2):
            if grid[i][j] == string[p+1]:
                if dfs(i,j,p+1):
                    return True
    grid[y][x] = string[p]
    return False

def has_solution(height, width):
    for i in range(1, height+1):
        for j in range(1, width+1):
            if grid[i][j]=='A':
                if dfs(i, j, 0):
                    return True
    return False

def main():
    global grid
    test = int(input())
    for i in range(test):
        height, width = [int(x) for x in input().split()]
        if width == 0 and height == 0:
            break
        grid = [['#']*(width+2) for i in range(height+2)]
        for i in range(1, height+1):
            string = input()
            for j in range(1, width+1):
                grid[i][j] = string[j-1]
        input()
        if has_solution(height, width):
            print("YES")
        else:
            print("NO")

main()
