#include <cstdio>

const int maxn = 1024;

char mtx[maxn][maxn];

int di[] = {1, 0,-1, 0};
int dj[] = {0, 1, 0, -1};

bool has_water_around(int i, int j) {
  for(int k=0; k<4; ++k)
    if (mtx[i+di[k]][j+dj[k]]=='.')
      return true;
  return false;
}

int main() {
  int n, m, coast;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<=n+1; ++i)
    for(int j=0; j<=m+1; ++j)
      mtx[i][j]='.';
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      scanf(" %c", &mtx[i][j]);
  coast=0;
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      if (mtx[i][j]=='#' && has_water_around(i, j)) {
        mtx[i][j]='o';
        ++coast;
      }
  printf("%d\n", coast);
  return 0;
}
