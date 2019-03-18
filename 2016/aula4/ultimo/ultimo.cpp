#include <cstdio>

const int maxn = 10100;
const int inf = 0x3f3f3f3f;

int mtx[maxn][maxn];
int day[maxn];
int que[maxn];
int front, back;

int main() {
  int n, k, m;
  int a, b;
  while(1) {
    scanf(" %d %d %d", &n, &k, &m);
    if (n==0&&k==0&&m==0)
      break;
    front = back = 0;
    for(int i=0; i<n; ++i) {
      day[i]=inf;
      for(int j=0; j<n; ++j)
        mtx[i][j]=0;
    }
    for(int i=0; i<k; ++i) {
      scanf(" %d", &a);
      --a;
      day[a]=0;
      que[back++]=a;
    }
    for(int i=0; i<m; ++i) {
      scanf(" %d %d", &a, &b);
      --a; --b;
      mtx[a][b]=1;
      mtx[b][a]=1;
    }
    while(front!=back) {
      a = que[front++];
      if (front==n)
        front = 0;
      for(int i=0; i<n; ++i) {
        if (mtx[a][i]) {
          if (day[i] > day[a]+1) {
            day[i] = day[a]+1;
            que[back++]=i;
            back=back%n;
          }
        }
      }
    }
    b = 0;
    for(int i=0; i<n; ++i)
      if (day[i] > b && day[i] < inf)
        b = day[i];
    a = 0;
    for(int i=0; i<n; ++i) {
      if (day[i]==b) {
        if (a==0) {
          printf("%d", i+1);
          a++;
        }
        else {
          printf(" %d", i+1);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
