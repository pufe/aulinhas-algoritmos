#include <cstdio>

const int mod = 10007;
const int maxn = 1024;

int dp[maxn][maxn];
char order[maxn];
bool before[maxn];

int main() {
  int n, m, t;
  scanf(" %d", &n);
  m=t=0;
  for(int i=0; i<n; ++i) {
    scanf(" %c", &order[i]);
    if (order[i]=='P') {
      order[i] = "OX"[m%2];
      ++m;
    }
    else {
      order[i] = "<>"[m%2];
    }
    before[i] = order[i]=='<' || order[i]=='O';
  }
  dp[0][0]=1;
  for(int i=1; i<n; ++i) {
    if (before[i])
      for(int j=i-1; j>=0; --j)
        dp[i][j]=(dp[i][j+1]+dp[i-1][j])%mod;
    else
      for(int j=1; j<=i; ++j)
        dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
  }
  for(int i=0; i<n; ++i)
    t=(t+dp[n-1][i])%mod;
  printf("%d\n", m%2==0?0:t);
  return 0;
}
