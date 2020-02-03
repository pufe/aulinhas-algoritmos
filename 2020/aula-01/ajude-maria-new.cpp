#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 26;

int mtx[maxn+1][maxn+1];
int sum[maxn+1][maxn+1];

int rect(int i1, int j1, int i2, int j2) {
  int low_i = min(i1, i2)-1;
  int hi_i = max(i1, i2);
  int low_j = min(j1, j2)-1;
  int hi_j = max(j1, j2);
  return sum[hi_i][hi_j]
    + sum[low_i][low_j]
    - sum[hi_i][low_j]
    - sum[low_i][hi_j];
}

bool test_condition(int n, int m) {
  for(int i1=1; i1<=maxn; ++i1)
    for(int j1=1; j1<=maxn; ++j1)
      if (mtx[i1][j1]>0)
        for(int i2=i1+1; i2<=maxn; ++i2)
          for(int j2=1; j2<=maxn; ++j2)
            if (mtx[i2][j2]>0 && j1!=j2)
              if (rect(i1,j1,i2,j2)==2)
                return false;
  return true;
}

bool solve() {
  int n, m, p;
  int x, y;
  if (scanf(" %d %d %d", &n, &m, &p)!=3)
    return false;
  for(int i=0; i<=maxn; ++i)
    for(int j=0; j<=maxn; ++j) {
      mtx[i][j]=0;
      sum[i][j]=0;
    }
  for(int i=0; i<p; ++i) {
    scanf(" %d %d", &x, &y);
    if (y<1 || y>maxn)
      throw 1;
    if (x<1 || x>maxn)
      throw 2;
    mtx[y][x]++;
  }
  for(int i=1; i<=maxn; ++i)
    for(int j=1; j<=maxn; ++j)
      sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mtx[i][j];
  if (p>1 && test_condition(n, m))
    printf("Y\n");
  else
    printf("N\n");
  return true;
}

int main() {
  while(solve())
    ;
  return 0;
}
