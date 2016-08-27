#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int huge;
const int inf = 0x3f3f3f3f;
const int maxn = 128 * 1024;

huge bit[maxn];

huge query(huge pos, huge n) {
  huge r = 0;
  for(; pos<=n; pos+=pos&-pos)
    r+=bit[pos];
  return r;
}
void update(huge pos, huge v, huge n) {
  for(; pos>0; pos-=pos&-pos)
    bit[pos]+=v;
}

int main() {
  huge n, m, p;
  huge x, t;
  scanf(" %lld %lld", &n, &m);
  for(int i=1; i<=n; ++i) {
    scanf(" %lld", &x);
    update(i, x, n);
    update(i-1, -x, n);
  }
  //debug(n);
  for(int i=0; i<m; ++i) {
    scanf(" %lld", &p);
    t = query(p, n);
    if (t>0) {
      if (p+t > n)
        update(n, -1ll, n);
      else
        update(p+t, -1ll, n);
      update(p-t-1, 1ll, n);
    }
    //debug(n);
  }
  x = 0;
  for(int i=1; i<=n; ++i) {
    t = query(i, n);
    if (t>0)
      x+=t;
  }
  printf("%lld\n", x);
  return 0;
}
