#include <cstdio>

const int maxn = 1024;
char graph[maxn][maxn];
int color[maxn];
int n;

void dfs(int p, int c) {
  color[p]=c;
  for(int i=0; i<n; ++i)
    if (graph[p][i]=='1' && color[i]==0)
      dfs(i, c);
}

int flood_fill() {
  for(int i=0; i<n; ++i)
    color[i]=0;
  int c=0;
  for(int i=0; i<n; ++i)
    if (color[i]==0)
      dfs(i, ++c);
  return c;
}

bool has_conflict() {
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
      if (color[i] == color[j] && graph[i][j]=='0')
        return true;
  return false;
}

bool read_input() {
  scanf(" %d", &n);
  if (n==0)
    return false;
  for(int i=0; i<n; ++i)
    scanf(" %s", graph[i]);
  return true;
}

void solve() {
  int c = flood_fill();
  if (has_conflict())
    printf("impossivel\n");
  else
    printf("%d\n", c);
}

int main() {
  while(read_input())
    solve();
  return 0;
}
