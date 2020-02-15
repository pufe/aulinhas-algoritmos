#include <cstdio>

const int maxn = 1024;
const int mod = 10007;

char line[maxn];
int dp[maxn][maxn];
int inverse[mod];
int choose_dp[maxn][maxn];

void flip(int p) {
  if (line[p]=='P')
    line[p]='B';
  else
    line[p]='P';
}
int calculate(int lb, int ub) {
  if (ub < lb)
    return 1;
  if (dp[lb][ub]>=0)
    return dp[lb][ub];
  //printf("calculate(%d, %d)\n", lb, ub);
  int total = 0;
  int c=0;
  flip(lb);
  flip(ub);
  for(int i=lb; i<=ub; ++i) {
    if (line[i]=='P') {
      if (c++ % 2 == 0) {
        total += calculate(lb, i-1)*calculate(i+1, ub)*choose_dp[ub-lb][ub-i];
        total %= mod;
      }
    }
    //printf("total=%d\n", total);
  }
  flip(lb);
  flip(ub);
  return dp[lb][ub]=total;
}

/*int euclid(int a, int b, int s, int t) {
  if (b==0)
    return s;
  int q = a/b;
  return euclid(b, a-q*b, t, ((s-q*t)%mod+mod)%mod);
}

int mult_inv(int n) {
  return euclid(n, mod, 1, 0);
}
*/
int main() {
  int n;
  inverse[0]=0;
  inverse[1]=1;
  /*for(int i=2; i<mod; ++i) {
    inverse[i]=mult_inv(i);
    }*/
  /*for(int i=0; i<mod; ++i) {
    printf("%d*%d = %d\n", i, inverse[i], i*inverse[i]%mod);
    }*/
  scanf(" %d", &n);
  choose_dp[0][0]=1;
  for(int i=1; i<=n; ++i) {
    choose_dp[i][0]=choose_dp[i][i]=1;
    for(int j=1; j<i; ++j)
      choose_dp[i][j]=(choose_dp[i-1][j-1]+choose_dp[i-1][j])%mod;
  }
  for(int i=0; i<n; ++i) {
    scanf(" %c", &line[i]);
  }
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      dp[i][j]=-1;
  flip(0);
  flip(n-1);
  for(int i=0; i<n; ++i) {
    for(int j=0; j+i<n; ++j) {
      calculate(j, j+i);
    }
  }
  /*for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      printf(" %3d", dp[i][j]);
    }
    printf("\n");
    }*/
  printf("%d\n", dp[0][n-1]);
  return 0;
}
