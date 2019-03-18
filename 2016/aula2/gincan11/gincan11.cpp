#include <cstdio>

const int maxn = 1000;
int color[maxn] = {};
int graph[maxn][maxn] = {};
int n;

void dfs(int v, int c) {
  if (color[v])
    return;
  color[v]=c;
  for(int i=0; i<n; ++i)
    if(graph[v][i])
      dfs(i,c);
}

int main() {
  int m, c, a, b;
  c=0;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<m; ++i) {
    scanf(" %d %d", &a, &b);
    graph[--a][--b]=1;
    graph[b][a]=1;
  }
  for(int i=0; i<n; ++i) {
    if (!color[i])
      dfs(i, ++c);
  }
  printf("%d\n", c);
  return 0;
}
