#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>
#include <cmath>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <set>
#include <string>
using namespace std;

const int maxn = 1<<17;
const int mask = (maxn<<1)-1;
const int inf = 0x3f3f3f3f;
int value[2*maxn];

inline int min(int a, int b) {
  return a<b?a:b;
}
inline int parent(int x) {
  return (x>>1)|maxn;
}
inline int left_child(int x) {
  return (x<<1)&mask;
}
inline int right_child(int x) {
  return ((x<<1)&mask)|1;
}
int query(int lb, int ub) {
  if (lb==ub)
    return value[lb];
  if (lb>ub)
    return inf;
  int answer = min(value[lb], value[ub]);
  if (lb&1)
    ++lb;
  if (!(ub&1))
    --ub;
  return min(answer, query(parent(lb), parent(ub)));
}
void update(int x) {
  if (x>=mask)
    return;
  value[x]=min(value[left_child(x)], value[right_child(x)]);
  update(parent(x));
}
int main() {
  int n, k;
  while(1) {
    scanf(" %d %d", &n, &k);
    if (n==0&&k==0)
      return 0;
    for(int i=0; i<n; ++i) {
      scanf(" %d", &value[i]);
      update(parent(i));
    }
    for(int i=0, j=k-1; j<n; ++i, ++j) {
      printf("%s%d", i==0?"":" ", query(i,j));
    }
    printf("\n");
  }
  return 0;
}
