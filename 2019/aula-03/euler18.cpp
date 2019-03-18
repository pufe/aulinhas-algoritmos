#include <cstdio>
#include <algorithm>
using namespace std;

int mtx[16][16];

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=i; ++j) {
      scanf(" %d", &mtx[i][j]);
    }
  }
  for(int i=n-1; i>0; --i) {
    for(int j=1; j<=i; ++j) {
      mtx[i][j]+=max(mtx[i+1][j], mtx[i+1][j+1]);
    }
  }
  printf("%d\n", mtx[1][1]);
  return 0;
}
