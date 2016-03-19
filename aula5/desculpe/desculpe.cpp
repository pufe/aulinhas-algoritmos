#include <cstdio>

const int maxn = 55;
const int maxk = 1010;

int mtx[maxn][maxk];
int valor[maxn];
int custo[maxn];

inline int max(int a, int b) {
  return (a>b) ? a : b;
}

int main() {
  int k, n;
  for(int t=1; ; ++t) {
    scanf(" %d %d", &k, &n);
    if (k==0&&n==0)
      break;
    for(int i=1; i<=n; ++i) {
      scanf(" %d %d", &custo[i], &valor[i]);
    }
    for(int i=0; i<=k; ++i) {
      for(int j=0; j<=n; ++j) {
        mtx[j][i] = 0;
      }
    }
    for(int i=1; i<=n; ++i) {
      for(int j=0; j<custo[i]; ++j)
        mtx[i][j] = mtx[i-1][j];
      for(int j=custo[i]; j<=k; ++j)
        mtx[i][j] = max(mtx[i-1][j],
                        mtx[i-1][j-custo[i]]+valor[i]);
    }
    printf("Teste %d\n%d\n\n", t, mtx[n][k]);
  }
  return 0;
}
