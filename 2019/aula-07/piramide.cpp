#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x3fff3fff;
const int maxn = 128;

int mtx[maxn][maxn];
int dp[maxn][maxn];

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      scanf(" %d", &mtx[i][j]);
    }
  }
  for(int i=0; i<=n; ++i) {
    for(int j=0; j<=n; ++j) {
      dp[i][j]=inf;
    }
  }
  dp[n][n]=0;
  for(int i=n-1; i>=0; --i) {
    int sum=0;
    for(int j=0; j<=i; ++j) {
      sum+=mtx[i][j];
    }
    for(int j=i; j<n; ++j) {
      dp[i][j]=min(dp[i+1][j], dp[i+1][j+1]) + sum;
      sum+=mtx[i][j+1]-mtx[i][j-i];
    }
  }
  int best = inf;
  for(int j=0; j<n; ++j) {
    best = min(best, dp[0][j]);
  }
  printf("%d\n", best);
  return 0;
}
