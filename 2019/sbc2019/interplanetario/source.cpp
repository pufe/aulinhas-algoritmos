#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long int huge;

const huge inf = 0x3fff3fff3fff3fffLL;
const int maxn = 405;

huge original_graph[maxn][maxn];
huge cold_dp[maxn][maxn][maxn];
huge hot_dp[maxn][maxn][maxn];
huge temperature[maxn];
int order[maxn];

bool compare_temperature(const int a, const int b) {
  return temperature[a] < temperature[b];
}
void debug(int n, int c) {
  for(int k=0; k<=c; ++k) {
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        if (cold_dp[i][j][k]<inf)
          printf(" %2lld", cold_dp[i][j][k]);
        else
          printf("  .");
      }
      printf("\t");
      for(int j=1; j<=n; ++j) {
        if (hot_dp[i][j][k]<inf)
          printf(" %2lld", hot_dp[i][j][k]);
        else
          printf("  .");
      }
      printf("\n");
    }
    printf("\n");
  }
}
int main() {
  int a, b, c, q, k, t;
  int repeat=0;
  huge d;
  int n, m;
  while(true) {
    if (scanf(" %d %d", &n, &m)!=2)
      break;
    repeat++;
    assert(repeat<=1);
    assert(n<=400);
    temperature[0] = -inf;
    for(int i=1; i<=n; ++i) {
      scanf(" %lld", &temperature[i]);
    }
    temperature[n+1] = inf;
    for(int i=0; i<n+2; ++i)
      order[i]=i;
    sort(order, order+n+2, compare_temperature);
    for(int i=1; i<=n; ++i)
      for(int j=1; j<=n; ++j)
        original_graph[i][j] = i==j?0LL:inf;
    for(int i=0; i<m; ++i) {
      scanf(" %d %d %lld", &a, &b, &d);
      original_graph[a][b] = min(original_graph[a][b], d);
      original_graph[b][a] = min(original_graph[b][a], d);
    }
    for(int i=1; i<=n; ++i)
      for(int j=1; j<=n; ++j) {
        cold_dp[i][j][0] = original_graph[i][j];
        hot_dp[i][j][0] = original_graph[i][j];
      }
    c=0;
    for(int kk=1; kk<=n; ++kk) {
      int k = order[kk];
      bool different = temperature[order[kk]]!=temperature[order[kk-1]] || true;
      if (different)
        ++c;
      for(int ii=1; ii<=n; ++ii) {
        int i=order[ii];
        for(int jj=1; jj<=n; ++jj) {
          int j=order[jj];
          if (different)
            cold_dp[i][j][c] = min(cold_dp[i][j][c-1],
                                   cold_dp[i][k][c-1]+cold_dp[k][j][c-1]);
          else
            cold_dp[i][j][c] = min(cold_dp[i][j][c],
                                   cold_dp[i][k][c]+cold_dp[k][j][c]);
        }
      }
    }
    c=0;
    for(int kk=1; kk<=n; ++kk) {
      int k = order[n-kk+1];
      bool different = temperature[order[n-kk+1]]!=temperature[order[n-kk+2]] || true;
      if (different)
        ++c;
      for(int ii=1; ii<=n; ++ii) {
        int i=order[n-ii+1];
        for(int jj=1; jj<=n; ++jj) {
          int j=order[n-jj+1];
          if (different)
            hot_dp[i][j][c] = min(hot_dp[i][j][c-1],
                                  hot_dp[i][k][c-1]+hot_dp[k][j][c-1]);
          else
            hot_dp[i][j][c] = min(hot_dp[i][j][c],
                                  hot_dp[i][k][c]+hot_dp[k][j][c]);
        }
      }
    }
    scanf(" %d", &q);
    for(int i=0; i<q; ++i) {
      scanf(" %d %d %d %d", &a, &b, &k, &t);
      if (k>c) {
        //printf("fodeu\n");
        k = min(k, c);
      }
      if (t==0) {
        if (cold_dp[a][b][k] < inf)
          printf("%lld\n", cold_dp[a][b][k]);
        else
          printf("-1\n");
      }
      else {
        if (hot_dp[a][b][k] < inf)
          printf("%lld\n", hot_dp[a][b][k]);
        else
          printf("-1\n");
      }
    }
  }
  return 0;
}
