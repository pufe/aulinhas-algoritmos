#include <cstdio>

const int maxn = 101;
const int inf = 0x3f3f3f3f;

int mtx[maxn][maxn];
int max_dist[maxn];

inline int min(int a, int b) {
  return a<b ? a : b;
}
inline int max(int a, int b) {
  return a>b ? a : b;
}
int main() {
  int n, m, a, b, c;
  int best_dist = inf;

  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i) {
    max_dist[i]=0;
    for(int j=0; j<n; ++j)
      mtx[i][j] = (i==j) ? 0 : inf;
  }
  for(int i=0; i<m; ++i) {
    scanf(" %d %d %d", &a, &b, &c);
    mtx[b][a] = mtx[a][b] = min(mtx[a][b], c);
  }
  for(int k=0; k<n; ++k)
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
        mtx[i][j]=min(mtx[i][j], mtx[i][k]+mtx[k][j]);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j)
      max_dist[i] = max(max_dist[i], mtx[i][j]);
    best_dist = min(best_dist, max_dist[i]);
  }
  printf("%d\n", best_dist);
  return 0;
}
