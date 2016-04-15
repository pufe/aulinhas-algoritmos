#include <cstdio>

struct point {
  int x;
  int y;
  int& operator[](int n) {
    if (n==0)
      return x;
    else
      return y;
  }
  point(int x=0, int y=0): x(x), y(y) {}
};

struct rect {
  point low;
  point hi;
  point operator[](int n) {
    switch (n) {
    case 0:
      return low;
    case 1:
      return hi;
    case 2:
      return point(low.x, hi.y);
    default:
      return point(hi.x, low.y);
    }
  }
};
const int maxn = 1010;
const int inf = 0x3f3f3f3f;

rect toldo[maxn];
int mtx[maxn][maxn];
int dist[maxn];
bool marked[maxn];

inline int min(int a, int b) {
  return a<b?a:b;
}

point read_point() {
  point tmp;
  scanf(" %d %d", &tmp.x, &tmp.y);
  return tmp;
}

rect read_rect() {
  rect tmp;
  tmp.low = read_point();
  tmp.hi = read_point();
  return tmp;
}

int calculate_distance(rect a, rect b) {
  int d[2] = {0,0};
  for(int i=0; i<2; ++i)
    if (a.hi[i] < b.low[i])
      d[i] = b.low[i] - a.hi[i];
    else if (a.low[i] > b.hi[i])
      d[i] = a.low[i] - b.hi[i];
  return d[0]+d[1];
}

void debug(int n) {
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j)
      if (mtx[i][j]==inf)
        printf(" oo");
      else
        printf(" %2d", mtx[i][j]);
    printf("\n");
  }
  printf("\n");
}

void dijkstra(int start, int n) {
  for(int i=0; i<n; ++i) {
    dist[i]=inf;
    marked[i]=false;
  }
  dist[start]=0;
  //debug(n);
  while(true) {
    int v=-1;
    int d=inf;
    for(int i=0; i<n; ++i)
      if (!marked[i] && dist[i]<d) {
        v=i;
        d=dist[i];
      }
    if (v==-1)
      break;
    marked[v]=true;
    for(int i=0; i<n; ++i)
      if (dist[i] > dist[v]+mtx[v][i])
        dist[i] = dist[v]+mtx[v][i];
  }
}

int main() {
  int n;
  toldo[0].low = toldo[0].hi = read_point();
  toldo[1].low = toldo[1].hi = read_point();
  scanf(" %d", &n);
  n+=2;
  for(int i=2; i<n; ++i)
    toldo[i] = read_rect();
  for(int i=0; i<n; ++i)
    for(int j=0; j<=i; ++j)
      mtx[i][j]=mtx[j][i]=calculate_distance(toldo[i], toldo[j]);
  dijkstra(0, n);
  printf("%d\n", dist[1]);
  return 0;
}
