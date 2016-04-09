#include <cstdio>

const struct {
  int dx;
  int dy;
} dir[4] = { { -1, 0},
             {0, -1},
             {1, 0},
             {0, 1} };

const int maxn = 110;
char mtx[maxn][maxn];

int dfs(int i, int j) {
  int ans=0;
  if (mtx[i][j]=='!')
    ans=1;
  if (mtx[i][j]=='#')
    ans=2;
  if (ans>0) {
    mtx[i][j]='x';
    for(int k=0; k<4; ++k)
      ans|=dfs(i+dir[k].dx, j+dir[k].dy);
  }
  return ans;
}
void debug(int n, int m) {
  for(int i=0; i<=n+1; ++i) {
    for(int j=0; j<=m+1; ++j)
      printf("%c", mtx[i][j]);
    printf("\n");
  }
  printf("------\n");
}

int main() {
  int n, m, a, b, k, count;
  count=0;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<=n+1; ++i)
    for(int j=0; j<=m+1; ++j)
      mtx[i][j] = 'x';

  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      scanf(" %c", &mtx[i][j]);
  //debug(n,m);
  scanf(" %d", &k);
  for(int i=0; i<k; ++i) {
    scanf(" %d %d", &a, &b);
    if(mtx[a][b]=='#')
      mtx[a][b]='!';
  }
  //debug(n,m);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      if (dfs(i,j)==1)
        ++count;
  //debug(n,m);
  printf("%d\n", count);
  return 0;
}
