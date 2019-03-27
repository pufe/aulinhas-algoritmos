#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int huge;
const huge mod = 1000000007;

huge arrange(huge n, huge k) {
  if (k<0)
    return 0;
  if (k>n)
    return 0;
  huge ans=1;
  for(huge i=0; i<k; ++i)
    ans=(ans*(n-i))%mod;
  //printf("arrange(%lld, %lld)=%lld\n", n, k, ans);
  return ans;
}
huge fatorial(huge n) {
  return arrange(n, n);
}
huge two(huge i) {
  return 1LL<<i;
}

int main() {
  huge n, k, j, g0, tmp, p, total, base;
  scanf(" %lld %lld", &n, &k);
  p = two(n);
  scanf(" %lld", &j);
  g0=0;
  total=0;
  for(huge i=1; i<p; ++i) {
    scanf(" %lld", &tmp);
    if (tmp<j)
      ++g0;
  }
  if (k==n+1) {
    if (g0 == p-1)
      printf("%lld\n", fatorial(p));
    else
      printf("0\n");
  }
  else {
    base = arrange(g0, two(k-1)-1);
    if (base!=0) {
      base = (base*two(n+k-1))%mod;
      base = (base*fatorial(two(n)-two(k)))%mod;
      for(huge gx=max(g0+1, two(k)-1); gx<p; ++gx) {
        total = (total+arrange(gx-two(k-1), two(k-1)-1))%mod;
      }
      total = (base*total)%mod;
      printf("%lld\n", total);
    }
    else {
      printf("0\n");
    }
  }
  return 0;
}
