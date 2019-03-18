#include <cstdio>
const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int mtx[maxn][maxn];
int dist[maxn];
bool visited[maxn];

int main() {
  int n, m, a, b, c;
  scanf(" %d %d", &n, &m);
  ++n;
  for(int i=0; i<=n; ++i) {
    visited[i]=false;
    dist[i]=inf;
    for(int j=0; j<=n; ++j)
      mtx[i][j]=inf;
  }

  for(int i=0; i<m; ++i) {
    scanf(" %d %d %d", &a, &b, &c);
    if (mtx[a][b]>c) {
      mtx[a][b]=c;
      mtx[b][a]=c;
    }
  }
  dist[0]=0;
  while(!visited[n]) {
    b=inf;
    a=-1;
    for(int i=0; i<=n; ++i)
      if (!visited[i] && b>dist[i]) {
        a = i;
        b = dist[i];
      }
    visited[a] = true;
    for(int i=0; i<=n; ++i)
      if(dist[i] > b+mtx[a][i])
        dist[i] = b+mtx[a][i];
  }
  printf("%d\n", dist[n]);
  return 0;
}
