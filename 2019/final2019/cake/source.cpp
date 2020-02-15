#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int huge;
const int maxn = 100100;
const int inf = 0x3fff3fff;

char cake[maxn];
int left[maxn];

int main() {
  int s, c, n;
  huge total = 0;
  scanf(" %s %d", cake, &s);
  n = strlen(cake);
  c = inf;
  for(int j=0; j<2; ++j) {
    for(int i=n-1; i>=0; --i) {
      if (cake[i]=='E')
        c=0;
      else
        c++;
      left[i] = c;
    }
  }
  for(int i=0; i<n; ++i) {
    total += max(s-left[i], 0);
  }
  printf("%lld\n", total);
  return 0;
}
