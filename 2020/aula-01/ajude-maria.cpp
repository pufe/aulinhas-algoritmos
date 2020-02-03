#include <cstdio>

int mtx[25][25];

int count_rect(int min_i, int max_i, int min_j, int max_j) {
  int c=0;
  for(int i=min_i; i<=max_i; ++i)
    for(int j=min_j; j<=max_j; ++j)
      c+=mtx[i][j];
  return c;
}

bool search_proof(int i, int j, int n, int m) {
  int min_i=i, max_i=i, min_j=j, max_j=j;
  while(min_i>0) {
    if (mtx[min_i-1][j]>0)
      break;
    min_i--;
  }
  while(min_j>0) {
    if (mtx[i][min_j-1]>0)
      break;
    min_j--;
  }
  while(max_i<n-1) {
    if (mtx[max_i+1][j]>0)
      break;
    max_i++;
  }
  while(max_j<m-1) {
    if (mtx[i][max_j+1]>0)
      break;
    max_j++;
  }
  return count_rect(min_i, max_i, min_j, max_j) > mtx[i][j];
}

bool test_condition(int n, int m) {
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      if (mtx[i][j] && search_proof(i, j, n, m))
        return false;
  return true;
}

bool solve() {
  int n, m, p;
  int x, y;
  if (scanf(" %d %d %d", &n, &m, &p)!=3)
    return false;
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      mtx[i][j]=0;
  for(int i=0; i<p; ++i) {
    scanf(" %d %d", &x, &y);
    --x;
    --y;
    ++mtx[x][y];
  }
  if (p>1 && test_condition(n, m))
    printf("Y\n");
  else
    printf("N\n");
  return true;
}

int main() {
  while(solve())
    ;
  return 0;
}
