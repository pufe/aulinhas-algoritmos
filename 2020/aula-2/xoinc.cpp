#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2048;

int coins[maxn];
int sum[maxn];
int dp[maxn][maxn];
int n;

int get_solution(int pos, int lim) {
  if (pos>n)
    return 0;

  if (lim > n-pos+1) {
    return dp[pos][n-pos+1];
  }
  return dp[pos][lim];
}

void solve(int pos, int lim) {
  dp[pos][lim] = sum[pos] - get_solution(pos+lim, lim*2);
  if (lim > 1) {
    dp[pos][lim] = max(dp[pos][lim], dp[pos][lim-1]);
  }
}

int main() {
  int s=0;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i) {
    scanf(" %d", &coins[i]);
  }
  for(int i=n; i>0; --i) {
    s+=coins[i];
    sum[i] = s;
  }
  for(int i=n; i>0; --i)
    for(int j=1; j+i<=n+1; ++j)
      solve(i, j);
  /*for(int j=1; j<=n; ++j) {
    for(int i=1; i<=n; ++i)
      printf(" %2d", dp[i][j]);
    printf("\n");
    }*/
  printf("%d\n", dp[1][2]);
  return 0;
}
