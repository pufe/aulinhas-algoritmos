#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int huge;
const int inf = 0x3f3f3f3f;
const int maxn = 1024;

int mtx[maxn][maxn];
int dist[maxn];
bool visit[maxn];

void dijkstra(int start, int n) {
  int current = start;
  int cd = 0;
  for(int i=0; i<n; ++i) {
    visit[i]=false;
    dist[i]=inf;
  }
  dist[start]=0;
  while(current != -1) {
    visit[current]=true;
    for(int i=0; i<n; ++i) {
      if (dist[i] > cd + mtx[current][i]) {
        dist[i] = cd + mtx[current][i];
      }
    }
    current = -1;
    cd = inf;
    for(int i=0; i<n; ++i) {
      if (!visit[i] && dist[i] < cd) {
        cd = dist[i];
        current = i;
      }
    }
  }
}

int main() {
  int n, m, a, b, k, q;
  char tmp;
  int tt=1;
  while(1) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
        mtx[i][j]=inf;
    for(int i=0; i<m; ++i) {
      scanf(" %d %d %d", &a, &b, &k);
      --a; --b;
      if (mtx[a][b] > k)
        mtx[a][b] = k;
    }
    scanf(" %d", &q);
    for(int i=0; i<q; ++i) {
      scanf(" %c", &tmp);
      switch(tmp) {
      case 'R':
        scanf(" %d %d", &a, &b);
        --a; --b;
        mtx[a][b]=inf;
        break;
      case 'I':
        scanf(" %d %d %d", &a, &b, &k);
        --a; --b;
        if (mtx[a][b]>k)
          mtx[a][b]=k;
        break;
      case 'P':
        scanf(" %d", &a);
        --a;
        dijkstra(0, n);
        if (dist[a]<inf)
          printf("%d\n", dist[a]);
        else
          printf("-1\n");
        break;
      default:
        printf("WTF\n");
        break;
      }
    }
    printf("\n", tt++);
  }
  return 0;
}
