#include <cstdio>

const int maxn = 1000;

char mtx[maxn][maxn];

int main() {
  int n, current, best;
  char cell;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      scanf(" %c", &mtx[i][j]);
  current=best=0;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if (i%2==0) {
        cell = mtx[i][j];
      }
      else {
        cell = mtx[i][n-j-1];
      }
      if (cell=='o')
        ++current;
      else if (cell=='A')
        current=0;
      if (current > best)
        best = current;
    }
  }
  printf("%d\n", best);
  return 0;
}
