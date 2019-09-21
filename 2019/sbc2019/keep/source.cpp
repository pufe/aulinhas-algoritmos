#include <cstdio>
using namespace std;

typedef long long int huge;
const huge mod = 1000000007L;

struct matrix_t {
  int h, w;
  huge v[4][4];
  matrix_t operator*(const matrix_t o) const {
    matrix_t r = {h, o.w, {}};
    for(int i=0; i<h; ++i)
      for(int j=0; j<o.w; ++j) {
        r.v[i][j]=0;
        for(int k=0; k<w; ++k) {
          r.v[i][j]+=v[i][k]*o.v[k][j];
          r.v[i][j]%=mod;
        }
      }
    return r;
  }
  huge sum() {
    huge r=0;
    for(int i=0; i<h; ++i)
      for(int j=0; j<w; ++j)
        r+=v[i][j];
    return r%mod;
  }
};

matrix_t M = {4, 4,
              {{2, 2, 0, 0},
               {0, 2, 2, 4},
               {0, 2, 0, 0},
               {0, 0, 0, 2}}};
matrix_t two = {4, 1,
                {{4, 0, 0, 0},
                 {8, 0, 0, 0},
                 {8, 0, 0, 0},
                 {4, 0, 0, 0}}};
matrix_t bin_exp(matrix_t base, int exp) {
  if (exp <= 1)
    return base;
  else if (exp%2==1)
    return base*bin_exp(base, exp-1);
  else
    return bin_exp(base*base, exp/2);
}
huge solve(int n) {
  if (n==1)
    return 2;
  if (n==2)
    return two.sum();
  else
    return (bin_exp(M, n-2)*two).sum();
}
int main() {
  int n;
  scanf(" %d", &n);
  printf("%lld\n", solve(n));
  return 0;
}
