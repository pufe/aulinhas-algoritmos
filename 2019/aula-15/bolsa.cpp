#include <cstdio>
#include <algorithm>
using namespace std;

struct purse_t {
  int q, v;
};
purse_t purse[4];
const int inf = 0x3fff3fff;
int dp[4][1001][101] = {};
bool calculated[4][1001][101] = {};

int profit(int t, int m, int p) {
  if (t==0) {
    if (p==0)
      return 0;
    else
      return -inf;
  }
  if (calculated[t][m][p])
    return dp[t][m][p];
  int best=profit(t-1, m, p);
  if (m>=purse[t].q) {
    if (p>0)
      best = max(best, profit(t, m-purse[t].q, p-1)+purse[t].v);
    best = max(best, profit(t, m-purse[t].q, p)+purse[t].v);
  }
  calculated[t][m][p] = true;
  dp[t][m][p] = best;
  return best;
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
