#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int huge;

const int maxn = 450;
const huge inf = 0x3fff3fff3fff;


// dp[a][b][k][0] = menor distância de a->b usando os k mais frios.
// dp[a][b][k][1] = menor distância de a->b usando os k mais quentes.

huge dp[maxn][maxn][maxn][2];
huge temp[maxn];
int order[maxn];
int cold_index[maxn];
int hot_index[maxn];

bool cmp(const int a, const int b) {
  return temp[a] < temp[b];
}

int main() {
  int n, m, q;
  huge a, b, c, k, t;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i) {
    scanf(" %lld", &temp[i]);
    order[i] = i;
  }

  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      for(int k=0; k<=n; ++k)
        if (i==j)
          dp[i][j][k][0] = dp[i][j][k][1] = 0;
        else
          dp[i][j][k][0] = dp[i][j][k][1] = inf;

  for(int i=0; i<m; ++i) {
    scanf(" %lld %lld %lld", &a, &b, &c);
    --a;--b;
    dp[a][b][0][0] = c;
    dp[b][a][0][0] = c;
    dp[a][b][0][1] = c;
    dp[b][a][0][1] = c;
  }
  sort(order, order+n, cmp);
  cold_index[0]=0;
  t=1;
  for(int i=1; i<n; ++i) {
    if (temp[order[i]] != temp[order[i-1]])
      cold_index[t++]=i;
  }
  for(;t<=n;++t)
    cold_index[t]=n;
  t=1;
  hot_index[0]=0;
  for(int i=1; i<n; ++i) {
    if (temp[order[n-i]] != temp[order[n-i-1]])
      hot_index[t++]=i;
  }
  for(;t<=n;++t)
    hot_index[t]=n;


  //floyd-warshall
  for(int k=1; k<=n; ++k) {
    int hot = order[n-k];
    int cold = order[k-1];
    //printf(" hot %d:%d, cold %d:%d\n", hot, temp[hot], cold, temp[cold]);
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j) {
        dp[i][j][k][0] = min(dp[i][j][k-1][0],
                             dp[i][cold][k-1][0]+dp[cold][j][k-1][0]);
        dp[i][j][k][1] = min(dp[i][j][k-1][1],
                             dp[i][hot][k-1][1]+dp[hot][j][k-1][1]);
      }
  }

  /*for(int i=0; i<=n; ++i) {
    if (i==0)
      printf("     ");
    else
      printf("%4d:", temp[order[i-1]]);
    printf(" %2d", hot_index[i]);
    printf(" %2d", cold_index[i]);
    printf("\n");
  }
  printf("\n");

  for(int k=0; k<=n; ++k) {
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        if (dp[i][j][k][0]<inf)
          printf(" %2d", dp[i][j][k][0]);
        else
          printf("  .");
      }
      printf("\t");
      for(int j=0; j<n; ++j) {
        if (dp[i][j][k][1]<inf)
          printf(" %2d", dp[i][j][k][1]);
        else
          printf("  .");
      }
      printf("\n");
    }
    printf("\n");
    }*/

  scanf(" %d", &q);
  for(int i=0; i<q; ++i) {
    scanf(" %lld %lld %lld %lld", &a, &b, &k, &t);
    --a;--b;
    if (t) {
      k = hot_index[k];
    }
    else {
      k = cold_index[k];
    }
    if (dp[a][b][k][t]<inf)
      printf("%lld\n", dp[a][b][k][t]);
    else
      printf("-1\n");
  }
  return 0;
}
