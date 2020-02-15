#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1024;
int arr[maxn];
int dp[maxn][maxn];

bool solve() {
  int n, k;
  if (scanf(" %d %d", &n, &k)!=2)
    return false;
  arr[0] = 0;
  arr[1] = 0;
  for(int i=2; i<=n; ++i)
    scanf(" %d", &arr[i]);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=k; ++j) {
      if (j>1) {
        dp[i][j] = min(dp[i-1][j-1],
                       arr[i]-arr[i-1]+dp[i-1][j]);
      }
      else {
        dp[i][j] = arr[i]-arr[i-1]+dp[i-1][j];
      }
    }
  }
  printf("%d\n", dp[n][k]);
  return true;
}

int main() {
  while(solve())
    ;
  return 0;
}
