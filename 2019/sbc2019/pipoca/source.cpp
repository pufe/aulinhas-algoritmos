#include <cstdio>
using namespace std;

typedef long long int huge;

const huge inf = 0x3f3fff3fffLL;
const huge maxn = 100100;
huge poki[maxn];
huge n, c, v;

bool is_possible(huge t) {
  huge total = t*v;
  huge people = 0;
  huge capacity = 0;
  for(huge i=0; i<n; ++i) {
    if (people > c)
      return false;
    if (capacity >= poki[i]) {
      capacity -= poki[i];
    }
    else {
      people++;
      capacity = total;
      --i;
    }
  }
  return true;
}

huge bin_search(huge lb, huge ub) {
  huge mid;
  while(lb<ub) {
    mid = (lb+ub)/2;
    if (is_possible(mid)) {
      ub = mid;
    }
    else {
      lb = mid+1;
    }
  }
  return lb;
}

int main() {
  scanf(" %lld %lld %lld", &n, &c, &v);
  for(int i=0; i<n; ++i) {
    scanf(" %lld", &poki[i]);
  }
  //printf("%d\n", inf);
  printf("%lld\n", bin_search(0, inf));
  return 0;
}
