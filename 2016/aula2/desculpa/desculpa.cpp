#include <cstdio>

const int maxk=1010;
int dp[maxk];

inline int max(int a, int b) {
  return a>b?a:b;
}
inline int min(int a, int b) {
  return a<b?a:b;
}

int main() {
  int n, k;
  int cost, value;
  for(int t=1;;++t) {
    scanf(" %d %d", &k, &n);
    if (n==0&&k==0)
      break;
    for(int i=0; i<=k; ++i)
      dp[i]=0;
    for(int i=0; i<n; ++i) {
      scanf(" %d %d", &cost, &value);
      for(int j=k; j>=cost; --j)
        dp[j]=max(dp[j],dp[j-cost]+value);
    }
    printf("Teste %d\n%d\n\n", t, dp[k]);
  }
  return 0;
}
