#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100100;
int pizza[maxn];
int dp[maxn];
int dpinv[maxn];

int main() {
  int n, best=0, total=0, best_inv=0;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &pizza[i]);
    total+=pizza[i];
  }
  for(int i=0; i<n; ++i) {
    if (i>0) {
      dp[i]=dp[i-1];
      dpinv[i]=dpinv[i-1];
    }
    else {
      dp[i]=0;
      dpinv[i]=0;
    }
    dp[i]+=pizza[i];
    dpinv[i]+=pizza[i];
    if (dp[i]<0) {
      dp[i]=0;
    }
    if (dpinv[i]>0) {
      dpinv[i]=0;
    }
    best = max(best, dp[i]);
    best_inv = min(best_inv, dpinv[i]);
  }
  /*for(int i=0; i<n; ++i) {
    printf(" %3d", dp[i]);
  }
  printf("\n");
  for(int i=0; i<n; ++i) {
    printf(" %3d", dpinv[i]);
  }
  printf("\n");*/
  printf("%d\n", max(best, total-best_inv));
  return 0;
}
