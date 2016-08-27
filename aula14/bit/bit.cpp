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
const int maxn = 1024;

int bit[maxn];
// binary indexed tree

int query(int pos, int n) {
  int r = 0;
  for(; pos<=n; pos+=pos&-pos) {
    r+=bit[pos];
  }
  return r;
}
void debug(int n) {
  printf("bit:  ");
  for(int i=1; i<=n; ++i)
    printf(" %2d", bit[i]);
  printf("\nquery:");
  for(int i=1; i<=n; ++i)
    printf(" %2d", query(i, n));
  printf("\n\n");
}
void update(int pos, int v, int n) {
  for(; pos>0; pos-=pos&-pos) {
    bit[pos]+=v;
  }
}
int main() {
  int n, x, st, ed, v;
  char cmd;
  scanf(" %d", &n);
  for(int i=0; i<=n; ++i)
    bit[i] = 0;

  bool running = true;
  while(running) {
    scanf(" %c", &cmd);
    switch(cmd) {
    case 'p':
      debug(n);
      break;
    case 'q':
      scanf(" %d", &x);
      printf("%d=%d\n", x, query(x, n));
      break;
    case 'a':
      scanf(" %d %d %d", &st, &ed, &v);
      if (st > 1)
        update(st-1, -v, n);
      update(ed, +v, n);
      break;
    case '!':
      running = false;
      break;
    }
  }
  return 0;
}
