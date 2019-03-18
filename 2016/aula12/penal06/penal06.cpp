#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1024;

int f2[maxn][maxn];
int f5[maxn][maxn];
int pen[maxn][maxn];

int calcula(int f[maxn][maxn], int n) {
  for(int i=n-1; i>=0; --i)
    for(int j=n-1; j>=0; --j) {
      pen[i][j]=inf;
      if (j<n-1)
        pen[i][j]=min(pen[i][j], pen[i][j+1]);
      if (i<n-1)
        pen[i][j]=min(pen[i][j], pen[i+1][j]);
      if (pen[i][j]==inf)
        pen[i][j]=0;
      pen[i][j] += f[i][j];
    }
  return pen[0][0];
}

int main() {
  int n, x;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      scanf(" %d", &x);
      if (x==0) {
        f2[i][j] = 1000000;
        f5[i][j] = 1000000;
      }
      else {
        while(x%2==0) {
          ++f2[i][j];
          x/=2;
        }
        while(x%5==0) {
          ++f5[i][j];
          x/=5;
        }
      }
    }
  }
  printf("%d\n", min(calcula(f2, n), calcula(f5, n)));
  return 0;
}
