#include <cstdio>
#include <algorithm>
using namespace std;

struct purse_t {
  int q, v;
};
purse_t purse[4];
const int inf = 0x3fff3fff;
int dp[4][1001][101] = {};

int profit(int t, int m, int p) {
  for(int i=0; i<=m; ++i)
    for(int j=0; j<=p; ++j)
      if (j==0)
        dp[0][i][j] = 0;
      else
        dp[0][i][j] = -inf;
  for(int k=1; k<=t; ++k) {
    for(int i=0; i<=m; ++i)
      for(int j=0; j<=p; ++j) {
        dp[k][i][j] = dp[k-1][i][j];
        if (i >= purse[k].q) {
          if (j > 0)
            dp[k][i][j] = max(dp[k][i][j], dp[k][i-purse[k].q][j-1] + purse[k].v);
          dp[k][i][j] = max(dp[k][i][j], dp[k][i-purse[k].q][j] + purse[k].v);
        }
      }
  }
  return dp[t][m][p];
}

int main() {
  int c, p;
  scanf(" %d %d", &c, &p);
  for(int i=1; i<=3; ++i) {
    scanf(" %d %d", &purse[i].q, &purse[i].v);
  }
  int r = profit(3, c, p);
  if (r >= 0)
    printf("%d\n", r);
  else
    printf("IMPOSSIBRU\n");
  return 0;
}
