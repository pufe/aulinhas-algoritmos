#include <cstdio>
enum status_t {
    unknown, safe, on_stack, unsafe
};
struct cell_t {
  char dir;
  status_t status;
};

const int maxn = 550;
cell_t mtx[maxn][maxn];

status_t dfs(int i, int j) {
  if (mtx[i][j].status != unknown)
    return mtx[i][j].status;
  mtx[i][j].status = on_stack;
  switch(mtx[i][j].dir) {
  case 'V':
    mtx[i][j].status=dfs(i+1, j);
    break;
  case 'A':
    mtx[i][j].status=dfs(i-1, j);
    break;
  case '<':
    mtx[i][j].status=dfs(i, j-1);
    break;
  case '>':
    mtx[i][j].status=dfs(i, j+1);
    break;
  }
  if (mtx[i][j].status == on_stack)
    mtx[i][j].status = safe;
  return mtx[i][j].status;
}

int main() {
  int n;
  int total=0;
  scanf(" %d", &n);
  for(int i=0; i<=n+1; ++i)
    for(int j=0; j<=n+1; ++j)
      if (i==0 || j==0 || i==n+1 || j==n+1)
        mtx[i][j].status = unsafe;
      else
        mtx[i][j].status = unknown;

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      scanf(" %c", &mtx[i][j].dir);
    }
  }
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) {
      if (mtx[i][j].status == unknown)
        dfs(i, j);
      if (mtx[i][j].status == safe)
        ++total;
    }
  printf("%d\n", total);
  return 0;
}
