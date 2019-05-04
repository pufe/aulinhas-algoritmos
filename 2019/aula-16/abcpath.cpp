#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 55;

char grid[maxn][maxn];
int longest[maxn][maxn];

int dfs(int y, int x) {
  if (longest[y][x] == 0) {
    int best = 0;
    for(int i=y-1; i<=y+1; ++i)
      for(int j=x-1; j<=x+1; ++j)
        if (grid[i][j] == grid[y][x]+1)
          best = max(best, dfs(i,j));
    longest[y][x]=best+1;
  }
  return longest[y][x];
}

int main() {
  int test=1;
  int height, width;
  int best;
  while(true) {
    scanf(" %d %d", &height, &width);
    if (height == 0 && width == 0)
      break;
    for(int i=0; i<=height+1; ++i)
      for(int j=0; j<=width+1; ++j){
        grid[i][j] = '#';
        longest[i][j] = 0;
      }
    for(int i=1; i<=height; ++i)
      for(int j=1; j<=width; ++j)
        scanf(" %c", &grid[i][j]);
    best=0;
    for(int i=1; i<=height; ++i)
      for(int j=1; j<=width; ++j)
        if (grid[i][j] == 'A')
          best = max(best, dfs(i,j));
    printf("Case %d: %d\n", test++, best);
  }
  return 0;
}
