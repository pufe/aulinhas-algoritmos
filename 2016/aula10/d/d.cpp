#include <cstdio>
const int inf = 0x3f3f3f3f;
const int maxn = 300;
int mtx[maxn][maxn] = {};

int dfs(int i, int j) {
  if (mtx[i][j])
    return 0;
  int count = 1;
  mtx[i][j]=1;
  for(int di=-1; di<=1; ++di)
    for(int dj=-1; dj<=1; ++dj)
      count+=dfs(i+di, j+dj);
  return count;
}

int main() {
  int n, m, k;
  int start_i, start_j;
  int tmp_i, tmp_j;

  scanf(" %d %d", &n, &m);
  for(int j=0; j<=m+1; ++j)
    mtx[0][j] = mtx[n+1][j] = 1;
  for(int i=0; i<=n+1; ++i)
    mtx[i][0] = mtx[i][m+1] = 1;
  scanf(" %d %d", &start_i, &start_j);
  scanf(" %d", &k);
  for(int i=0; i<k; ++i) {
    scanf(" %d %d", &tmp_i, &tmp_j);
    mtx[tmp_i][tmp_j] = 1;
  }
  printf("%d\n", dfs(start_i, start_j));
  return 0;
}
