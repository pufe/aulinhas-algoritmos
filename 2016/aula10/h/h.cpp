#include <cstdio>
const int inf = 0x3f3f3f3f;
const int maxn = 1100;

struct point {
  int x, y;
};

int dist(point a, point b){
  int dx = a.x-b.x, dy=a.y-b.y;
  return dx*dx + dy*dy;
}

point tree[maxn];
bool mtx[maxn][maxn];
bool visited[maxn];

void dfs(int v, int n) {
  if (!visited[v]) {
    visited[v]=true;
    for(int i=0; i<n; ++i)
      if (mtx[v][i])
        dfs(i,n);
  }
}

int main() {
  int n, maxd;
  bool all_visited = true;

  scanf(" %d %d", &n, &maxd);
  maxd *= maxd;
  for(int i=0; i<n; ++i) {
    scanf(" %d %d", &tree[i].x, &tree[i].y);
    visited[i]=false;
  }
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      mtx[i][j] = dist(tree[i], tree[j]) <= maxd;
  dfs(0, n);
  for(int i=0; i<n; ++i)
    if(!visited[i])
      all_visited=false;
  printf(all_visited?"S\n":"N\n");
  return 0;
}
