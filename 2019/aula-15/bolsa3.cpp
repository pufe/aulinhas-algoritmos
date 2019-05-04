#include <cstdio>
#include <algorithm>
using namespace std;

struct purse_t {
  int q, v;
};
purse_t purse[4];
const int inf = 0x3fff3fff;

int profit(int t, int m, int p) {
  int best = -inf;
  for(int a=0; a<=1000; ++a)
    for(int b=0; b<=1000; ++b) {
      int material = (m - a*purse[1].q - b*purse[2].q);
      if (material < 0)
        continue;
      int c = material/purse[3].q;
      if (a+b+c<p)
        continue;
      best = max(best, a*purse[1].v + b*purse[2].v + c*purse[3].v);
    }
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
